#ifndef PCAPWORKER_H
#define PCAPWORKER_H

#include <QObject>
#include <QStandardItemModel>
#include <pcap/pcap.h>
#include <CapturedPacket.h>

class PcapWorker : public QObject
{
    Q_OBJECT

public:
    int packetCount = 0;
    explicit PcapWorker(pcap_t *adhandle, QStandardItemModel *model, QObject *parent = nullptr);
    ~PcapWorker();
    static std::vector<CapturedPacket> allPackets;


signals:
    void paqueteCapturado(const QList<QStandardItem *> &fila);
    void capturaFinalizada();

public slots:
    void iniciarCaptura();
    void detenerCapturaa();

private:
    pcap_t *adhandle;
    QStandardItemModel *model;
    bool continuar;

    static void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data);


};

#endif // PCAPWORKER_H
