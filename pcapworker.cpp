#include "pcapworker.h"
#include <QDateTime>
#include <QThread> // Para QThread::msleep
#include <winsock2.h>
#include <ws2tcpip.h>
#include <QDebug>
#include <QStandardItem>

std::vector<CapturedPacket> PcapWorker::allPackets;




PcapWorker::PcapWorker(pcap_t *adhandle, QStandardItemModel *model, QObject *parent)
    : QObject(parent), adhandle(adhandle), model(model), continuar(true)
{
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        qWarning() << "Error al inicializar Winsock.";
    }
}

PcapWorker::~PcapWorker()
{
    // No cerramos adhandle aquí, lo hace menu_program
    WSACleanup();
}

void PcapWorker::iniciarCaptura()
{
    qInfo() << "Iniciando captura de paquetes con hilos.";

    if (!adhandle) {
        qWarning() << "Handle no válido, no se puede iniciar pcap_loop.";
        emit capturaFinalizada();
        return;
    }

    int result = pcap_loop(adhandle, 0, packet_handler, reinterpret_cast<u_char *>(this));
    if (result < 0) {
        qWarning() << "Error en pcap_loop:" << pcap_geterr(adhandle);
    }

    emit capturaFinalizada();
}

void PcapWorker::detenerCapturaa()
{
    qInfo() << "Deteniendo captura de paquetes.";
    continuar = false;
    if (adhandle)
        pcap_breakloop(adhandle);
}

void PcapWorker::packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
    auto *worker = reinterpret_cast<PcapWorker *>(param);
    if (!worker || !worker->adhandle) return;

    if (header->caplen < 34) {
        return;
    }

    worker->packetCount++;

    const ip_header *ih = (const ip_header *)(pkt_data + 14);
    QString fuente = QString("%1.%2.%3.%4")
                         .arg(ih->saddr.byte1)
                         .arg(ih->saddr.byte2)
                         .arg(ih->saddr.byte3)
                         .arg(ih->saddr.byte4);

    QString destino = QString("%1.%2.%3.%4")
                          .arg(ih->daddr.byte1)
                          .arg(ih->daddr.byte2)
                          .arg(ih->daddr.byte3)
                          .arg(ih->daddr.byte4);

    TransportProtocol protoType = TransportProtocol::OTRO;

    QString protocolo;
    if (ih->proto == 6) {
        protocolo = "TCP";
        protoType = TransportProtocol::TCP;
    } else if (ih->proto == 17) {
        protocolo = "UDP";
        protoType = TransportProtocol::UDP;
    } else {
        protocolo = "Otro";
    }

    QString longitud = QString::number(header->len);
    QString informacion = "Paquete procesado";


    QString tiempo = QDateTime::currentDateTime().toString("hh:mm:ss.zzz");


    // Guardar el paquete en allPackets
    CapturedPacket packet;
    packet.packetNumber = worker->packetCount;
    packet.timestamp = QDateTime::currentDateTime();
    packet.ip = *ih; // copiar ip_header
    packet.protocol = protoType;
    packet.rawData.assign(pkt_data, pkt_data + header->caplen);

    // Si es TCP o UDP, parseamos el header:
    const u_char *transportData = pkt_data + 14 + ((ih->ver_ihl & 0x0F)*4);
    if (protoType == TransportProtocol::TCP && (header->caplen >= 14 + ((ih->ver_ihl & 0x0F)*4) + sizeof(tcp_header))) {
        packet.tcp = *(const tcp_header*)transportData;
    } else if (protoType == TransportProtocol::UDP && (header->caplen >= 14 + ((ih->ver_ihl & 0x0F)*4) + sizeof(udp_header))) {
        packet.udp = *(const udp_header*)transportData;
    }

    allPackets.push_back(packet);

    QList<QStandardItem *> fila;
    fila << new QStandardItem(QString::number(worker->packetCount))
         << new QStandardItem(tiempo)
         << new QStandardItem(fuente)
         << new QStandardItem(destino)
         << new QStandardItem(protocolo)
         << new QStandardItem(longitud)
         << new QStandardItem(informacion);



    QThread::msleep(100); // Retraso de 100 ms
    emit worker->paqueteCapturado(fila);

}
