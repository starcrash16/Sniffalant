#include "menu_program.h"
#include "ui_menu_program.h"
#include <QDebug>
#include <QDateTime>
#include <QStandardItem>
#include <pcap/winsock2.h>
#include <ws2tcpip.h>
#include <QHBoxLayout>
#include <QListWidgetItem>
#include <QWidget>
#include <iostream>
#include <string>
#include <cstring> // Para usar strcpy
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QCloseEvent>
#include <QApplication>
#include <QMessageBox>
#include <QMap>
#include <QDebug>

using namespace std;



menu_program::menu_program(int idDisp, pcap_if_t *alldevs, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::menu_program),
    dispositivoSeleccionado(nullptr),
    adhandle(nullptr),
    workerThread(new QThread(this)),
    worker(nullptr),
    model(new QStandardItemModel(this))
{
    int contador = 0;
    for (pcap_if_t *temp = alldevs; temp != nullptr; temp = temp->next) {
        if (contador == idDisp) {
            dispositivoSeleccionado = temp;
            break;
        }
        contador++;
    }

    ui->setupUi(this);
    setWindowTitle("Sniffalant");


    QMenuBar *menuBar = new QMenuBar(this);
    setMenuBar(menuBar);

    // === 2. Crear menús y submenús ===
    QMenu *menuPrograma = menuBar->addMenu("Programa");
    QMenu *menuExportar = menuBar->addMenu("Exportar");
    QMenu *menuCaptura = menuBar->addMenu("Captura");
    QMenu *menuEstadisticas = menuBar->addMenu("Estadísticas");
    QMenu *menuAyuda = menuBar->addMenu("Ayuda");

    // Submenús y acciones para "Programa"
    QAction *accionSeleccionarDispositivo = new QAction("Regresar Menu Dispositivos", this);
    QAction *salir= new QAction("Salir", this);
    menuPrograma->addAction(accionSeleccionarDispositivo);
    menuPrograma->addAction(salir);

    // Submenús y acciones para "Exportar"
    QAction *accionExportarCSV = new QAction("Exportar a CSV", this);
    menuExportar->addAction(accionExportarCSV);

    // Submenús y acciones para "Captura"


    // Submenús y acciones para "Estadísticas"
    QAction *accionEstadisticas = new QAction("Mostrar Estadísticas", this);
    menuEstadisticas->addAction(accionEstadisticas);

    // Submenús y acciones para "Ayuda"
    QAction *accionAyuda = new QAction("Ayuda", this);
    menuAyuda->addAction(accionAyuda);

    // === 3. Conectar las acciones con sus respectivos slots ===
    connect(accionSeleccionarDispositivo, &QAction::triggered, this, []() {
        qDebug() << "Seleccionar Dispositivo clickeado";
    });

    connect(accionExportarCSV, &QAction::triggered, this, &menu_program::exportarCSV);



    connect(accionEstadisticas, &QAction::triggered, this, &menu_program::mostrarEstadisticas);


    connect(accionAyuda, &QAction::triggered, this, &menu_program::abrirPaginaWeb);


    // Definir las cabeceras del modelo
    model->setHorizontalHeaderLabels({"No.", "Tiempo", "Fuente", "Destino", "Protocolo", "Longitud", "Información"});
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);

    int columnCount = ui->tableView->model()->columnCount();
    int uniformWidth = 180;
    for (int col = 0; col < columnCount; ++col) {
        ui->tableView->setColumnWidth(col, uniformWidth);
    }

    connect(ui->tableView, &QTableView::clicked, this, &menu_program::on_tableView_clicked);

    // Crear el centralWidget y el layout principal
    centralWidgetContainer = new QWidget(this);
    mainLayout = new QVBoxLayout(centralWidgetContainer);
    centralWidgetContainer->setLayout(mainLayout);
    setCentralWidget(centralWidgetContainer);

    QHBoxLayout *nameLayout = new QHBoxLayout();
    QString nom = dispositivoSeleccionado->description;
    QString nameD = "Escuchando al dispositivo: " + nom;
    QLabel *nombreDispositivo = new QLabel(nameD,this);
    nameLayout->addWidget(nombreDispositivo);
    mainLayout->addLayout(nameLayout);

    // Crear el layout para los filtros en la parte superior
    QHBoxLayout *filtersLayout = new QHBoxLayout();

    // Crear el QLabel y los QPushButton

    QLabel *filtrosLabel = new QLabel("Filtros de Paquetes:", this);
    QPushButton *btnUDP = new QPushButton("UDP", this);
    QPushButton *btnTCP = new QPushButton("TCP", this);
    QPushButton *btnOtros = new QPushButton("Otros", this);

    connect(btnUDP, &QPushButton::clicked, this, &menu_program::on_btnUDP_clicked);
    connect(btnTCP, &QPushButton::clicked, this, &menu_program::on_btnTCP_clicked);
    connect(btnOtros, &QPushButton::clicked, this, &menu_program::on_btnOtros_clicked);

    // Agregar los widgets al layout de filtros
    filtersLayout->addWidget(filtrosLabel);
    filtersLayout->addWidget(btnUDP);
    filtersLayout->addWidget(btnTCP);
    filtersLayout->addWidget(btnOtros);
    filtersLayout->addStretch(); // Para empujar los widgets hacia la izquierda y llenar espacio

    // Agregar el layout de filtros al mainLayout, antes de la tabla
    mainLayout->addLayout(filtersLayout);

    // Ahora agregar la tabla debajo de los filtros
    mainLayout->addWidget(ui->tableView);

    // Crear el layout inferior con dos QScrollArea lado a lado
    bottomLayout = new QHBoxLayout();
    mainLayout->addLayout(bottomLayout);

    structuredArea = new QScrollArea;
    structuredArea->setWidgetResizable(true);
    structuredContainer = new QWidget;
    structuredLayout = new QFormLayout(structuredContainer);
    structuredArea->setWidget(structuredContainer);

    rawArea = new QScrollArea;
    rawArea->setWidgetResizable(true);
    rawTextEdit = new QPlainTextEdit;
    rawTextEdit->setReadOnly(true);
    rawArea->setWidget(rawTextEdit);

    bottomLayout->addWidget(structuredArea);
    bottomLayout->addWidget(rawArea);



    if (dispositivoSeleccionado) {

        iniciarCaptura();
    } else {
        qWarning() << "No se encontró el adaptador con ID:" << idDisp;
    }
}

menu_program::~menu_program()
{
    workerThread->quit();
    workerThread->wait();

    delete ui;

    if (adhandle) {
        pcap_close(adhandle);
        adhandle = nullptr;
    }
}


QString menu_program::definir_Filtro() {
    if (protocolActualFilter == "udp") {
        return "udp";
    } else if (protocolActualFilter == "tcp") {
        return "tcp";
    } else {
        return " ";
    }
}




void menu_program::iniciarCaptura()
{
    u_int netmask;
    struct bpf_program fcode;
    //char packet_filter[] = "udp";

    // Obtener el filtro como std::string
    QString filtro = definir_Filtro();

    // Convertir el QString a QByteArray (por ejemplo usando Latin1)
    QByteArray filterArray = filtro.toLatin1();

    // Obtener un apuntador const char* a los datos del QByteArray
    const char *packet_filter = filterArray.constData();


    qDebug() << "Filtro CAMBIADO: " << protocolActualFilter;
    if (!dispositivoSeleccionado) {
        qWarning() << "No hay adaptador seleccionado.";
        return;
    }

    char errbuf[PCAP_ERRBUF_SIZE];
    //ui->label->setText(texto);

    qInfo() <<"INFO: " << dispositivoSeleccionado->name;

    adhandle = pcap_open_live(dispositivoSeleccionado->name, 65536, 1, 1000, errbuf);



    if (adhandle == nullptr) {
        qWarning() << "No se pudo abrir el adaptador:" << errbuf;
        return;
    }


        /* Check the link layer. We support only Ethernet for simplicity. */
    if (pcap_datalink(adhandle) != DLT_EN10MB)
    {
        qWarning() << "This program works only on Ethernet networks.";
    }

    if (dispositivoSeleccionado->addresses != NULL)
        netmask = ((struct sockaddr_in*)(dispositivoSeleccionado->addresses->netmask))->sin_addr.S_un.S_addr;
    else
        netmask = 0xFFFFFFFF; // Red completa, sin suponer clase C.


    //compile the filter
    if (pcap_compile(adhandle, &fcode, packet_filter, 1, netmask) < 0) {
        qWarning() << "Error compilando el filtro:" << pcap_geterr(adhandle);
        return;
    }

    if (pcap_setfilter(adhandle, &fcode) < 0) {
        qWarning() << "Error estableciendo el filtro:" << pcap_geterr(adhandle);
        return;
    }



    capturaCorriendo = true;
    worker = new PcapWorker(adhandle, model);
    worker->moveToThread(workerThread);

    connect(workerThread, &QThread::started, worker, &PcapWorker::iniciarCaptura);
    connect(worker, &PcapWorker::paqueteCapturado, this, &menu_program::agregarPaquete);
    //Verificar este
    connect(worker, &PcapWorker::capturaFinalizada, this, &menu_program::finalizarCaptura);

    connect(workerThread, &QThread::finished, worker, &QObject::deleteLater);
    connect(worker, &QObject::destroyed, workerThread, &QObject::deleteLater);

    workerThread->start();
}

void menu_program::agregarPaquete(const QList<QStandardItem*> &fila)
{
    model->appendRow(fila);
}

void menu_program::finalizarCaptura()
{
    qInfo() << "Captura finalizada.";
    workerThread->quit();
    workerThread->wait();
}



void menu_program::on_tableView_clicked(const QModelIndex &index)
{
    mostrarDetallesPaquete(index);
}

void menu_program::mostrarDetallesPaquete(const QModelIndex &index)
{
    if (!index.isValid()) return;

    // Obtener número de paquete desde la tabla (columna "No.")
    QString no = model->item(index.row(), 0)->text();
    int packetNo = no.toInt();

    // Limpiar el layout estructurado
    QLayoutItem *child;
    while ((child = structuredLayout->takeAt(0)) != nullptr) {
        if (child->widget()) {
            child->widget()->deleteLater();
        }
        delete child;
    }

    // Buscar el paquete en allPackets
    const CapturedPacket *foundPacket = nullptr;
    for (const auto &p : PcapWorker::allPackets) {
        if (p.packetNumber == packetNo) {
            foundPacket = &p;
            break;
        }
    }

    if (!foundPacket) {
        structuredLayout->addRow("Error:", new QLabel("Paquete no encontrado"));
        return;
    }

    const CapturedPacket &packet = *foundPacket;

    // Mostrar información IP base (ya tienes IP Fuente, IP Destino, podemos mostrar campos adicionales):
    structuredLayout->addRow("IP ver_ihl (Versión + Longitud cabecera):", new QLabel(QString::number(packet.ip.ver_ihl)));
    structuredLayout->addRow("IP ToS (Tipo de servicio):", new QLabel(QString::number(packet.ip.tos)));
    structuredLayout->addRow("IP Total Length (Longitud total):", new QLabel(QString::number(ntohs(packet.ip.tlen))));
    structuredLayout->addRow("IP Identification (Identificación):", new QLabel(QString::number(ntohs(packet.ip.identification))));
    structuredLayout->addRow("IP Flags_FO (Banderas + Offset de fragmento):", new QLabel(QString::number(ntohs(packet.ip.flags_fo))));
    structuredLayout->addRow("IP TTL (Tiempo de vida):", new QLabel(QString::number(packet.ip.ttl)));
    structuredLayout->addRow("IP Proto (Protocolo):", new QLabel(QString::number(packet.ip.proto)));
    structuredLayout->addRow("IP Checksum (Suma de verificación):", new QLabel(QString::number(ntohs(packet.ip.crc))));

    // Direcciones IP ya las mostraste antes como Fuente/Destino, pero puedes volver a mostrarlas con más detalle si gustas:
    QString fuente = QString("%1.%2.%3.%4")
                         .arg(packet.ip.saddr.byte1)
                         .arg(packet.ip.saddr.byte2)
                         .arg(packet.ip.saddr.byte3)
                         .arg(packet.ip.saddr.byte4);

    QString destino = QString("%1.%2.%3.%4")
                          .arg(packet.ip.daddr.byte1)
                          .arg(packet.ip.daddr.byte2)
                          .arg(packet.ip.daddr.byte3)
                          .arg(packet.ip.daddr.byte4);

    structuredLayout->addRow("IP Fuente (Dirección IP origen):", new QLabel(fuente));
    structuredLayout->addRow("IP Destino (Dirección IP destino):", new QLabel(destino));


    // Dependiendo del protocolo, mostrar campos TCP o UDP
    switch (packet.protocol) {
    case TransportProtocol::TCP:
        structuredLayout->addRow("TCP Sport (Puerto origen):", new QLabel(QString::number(ntohs(packet.tcp.sport))));
        structuredLayout->addRow("TCP Dport (Puerto destino):", new QLabel(QString::number(ntohs(packet.tcp.dport))));
        structuredLayout->addRow("TCP SeqNum (Número de secuencia):", new QLabel(QString::number(ntohl(packet.tcp.seqnum))));
        structuredLayout->addRow("TCP AckNum (Número de acuse de recibo):", new QLabel(QString::number(ntohl(packet.tcp.acknum))));
        structuredLayout->addRow("TCP Data Offset (Desplazamiento datos, 4 bits):", new QLabel(QString::number(packet.tcp.data_offset)));
        structuredLayout->addRow("TCP Flags (Banderas de control):", new QLabel(QString::number(packet.tcp.flags)));
        structuredLayout->addRow("TCP Win (Tamaño de ventana):", new QLabel(QString::number(ntohs(packet.tcp.win))));
        structuredLayout->addRow("TCP Checksum (Suma de verificación):", new QLabel(QString::number(ntohs(packet.tcp.crc))));
        structuredLayout->addRow("TCP UrgPtr (Puntero urgente):", new QLabel(QString::number(ntohs(packet.tcp.urgptr))));
        break;

    case TransportProtocol::UDP:
        structuredLayout->addRow("Protocolo:", new QLabel("UDP"));
        structuredLayout->addRow("UDP Sport (Puerto origen):", new QLabel(QString::number(ntohs(packet.udp.sport))));
        structuredLayout->addRow("UDP Dport (Puerto destino):", new QLabel(QString::number(ntohs(packet.udp.dport))));
        structuredLayout->addRow("UDP Length (Longitud del datagrama UDP):", new QLabel(QString::number(ntohs(packet.udp.len))));
        structuredLayout->addRow("UDP Checksum (Suma de verificación):", new QLabel(QString::number(ntohs(packet.udp.crc))));break;

    case TransportProtocol::OTRO:
    default:
        structuredLayout->addRow("Protocolo:", new QLabel("Otro/Desconocido"));
        break;
    }

    // Si quieres, puedes mostrar también el tamaño del rawData:
    structuredLayout->addRow("Raw Data Length:", new QLabel(QString::number(packet.rawData.size())));

    // Muestra el rawData en el text area (ya lo tienes implementado)
    rawTextEdit->clear();
    rawTextEdit->appendPlainText("Raw Data (Hex):\n");
    QString hexDump;
    hexDump.reserve(packet.rawData.size() * 3);
    for (auto byte : packet.rawData) {
        hexDump += QString("%1 ").arg(byte, 2, 16, QLatin1Char('0'));
    }
    rawTextEdit->appendPlainText(hexDump.trimmed());
}



void menu_program::exportarCSV() {
    qDebug() << "Botón Exportar a CSV presionado";

    // 1. Abrir un QFileDialog para que el usuario seleccione la ubicación del archivo
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    "Guardar como CSV",
                                                    QDir::homePath() + "/captura_paquetes.csv",
                                                    "CSV Files (*.csv)");

    if (fileName.isEmpty()) {
        qWarning() << "Exportación cancelada por el usuario.";
        return; // Si el usuario cancela, no hacemos nada
    }

    // 2. Abrir el archivo seleccionado
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "No se pudo abrir el archivo para escritura.");
        return;
    }

    // 3. Crear un QTextStream para escribir en el archivo
    QTextStream out(&file);

    // 4. Escribir el encabezado del CSV
    out << "No.,Tiempo,Fuente,Destino,Protocolo,Longitud,Información\n";

    // 5. Recorrer el vector y escribir cada paquete en el archivo
    for (size_t i = 0; i < PcapWorker::allPackets.size(); ++i) {
        const CapturedPacket &packet = PcapWorker::allPackets[i];

        // Convertir datos a texto CSV (modificar según los campos reales de CapturedPacket)
        QString tiempo = packet.timestamp.toString("hh:mm:ss.zzz"); // Suponiendo que hay un timestamp
        QString fuente = QString("%1.%2.%3.%4")
                             .arg(packet.ip.saddr.byte1)
                             .arg(packet.ip.saddr.byte2)
                             .arg(packet.ip.saddr.byte3)
                             .arg(packet.ip.saddr.byte4);
        QString destino = QString("%1.%2.%3.%4")
                              .arg(packet.ip.daddr.byte1)
                              .arg(packet.ip.daddr.byte2)
                              .arg(packet.ip.daddr.byte3)
                              .arg(packet.ip.daddr.byte4);
        QString protocolo = (packet.protocol == TransportProtocol::TCP) ? "TCP" :
                                (packet.protocol == TransportProtocol::UDP) ? "UDP" : "Otro";
        QString longitud = QString::number(packet.rawData.size());
        QString informacion = "Detalles adicionales"; // Ajusta según lo que quieras exportar

        // Escribir la fila en el archivo
        out << i + 1 << ","
            << tiempo << ","
            << fuente << ","
            << destino << ","
            << protocolo << ","
            << longitud << ","
            << informacion << "\n";
    }

    file.close();
    QMessageBox::information(this, "Exportación Exitosa", "Los paquetes han sido exportados a CSV correctamente.");
}



void menu_program::on_btnUDP_clicked() {
    protocolActualFilter = "udp";
    iniciarCaptura();
}

void menu_program::on_btnTCP_clicked() {
    protocolActualFilter = "tcp";
    iniciarCaptura();

}

void menu_program::on_btnOtros_clicked() {
    protocolActualFilter = "otro";
    iniciarCaptura();
}

void menu_program::on_btnLimpiarF_clicked() {
    protocolActualFilter = "";
    iniciarCaptura();
}

void menu_program::closeEvent(QCloseEvent *event) {
    // Mostrar un mensaje de confirmación opcional
    int respuesta = QMessageBox::question(this, "Cerrar Programa",
                                          "¿Estás seguro de que deseas cerrar el programa?",
                                          QMessageBox::Yes | QMessageBox::No);

    if (respuesta == QMessageBox::Yes) {
        // Cerrar completamente la aplicación
        qDebug() << "Cerrando la aplicación...";
        QApplication::quit(); // Cierra todos los hilos y termina el programa
    } else {
        // Cancelar el evento de cierre
        event->ignore();
    }
}

void menu_program::mostrarEstadisticas() {
    if (PcapWorker::allPackets.empty()) {
        QMessageBox::information(this, "Estadísticas", "No hay paquetes capturados para mostrar estadísticas.");
        return;
    }

    int totalPaquetes = PcapWorker::allPackets.size();
    int totalTCP = 0, totalUDP = 0, totalOtros = 0;
    double sumaLongitudTCP = 0, sumaLongitudUDP = 0, sumaLongitudOtros = 0;

    // Para IP Destino más frecuente
    QMap<QString, int> conteoIPsDestino;

    int paqueteMaximo = 0; // Longitud máxima del paquete

    // 1. Recorrer el vector para calcular estadísticas
    for (const CapturedPacket &packet : PcapWorker::allPackets) {
        int longitud = packet.rawData.size();
        paqueteMaximo = std::max(paqueteMaximo, longitud);

        // Contar por protocolo
        if (packet.protocol == TransportProtocol::TCP) {
            totalTCP++;
            sumaLongitudTCP += longitud;
        } else if (packet.protocol == TransportProtocol::UDP) {
            totalUDP++;
            sumaLongitudUDP += longitud;
        } else {
            totalOtros++;
            sumaLongitudOtros += longitud;
        }

        // Contar IP Destino
        QString ipDestino = QString("%1.%2.%3.%4")
                                .arg(packet.ip.daddr.byte1)
                                .arg(packet.ip.daddr.byte2)
                                .arg(packet.ip.daddr.byte3)
                                .arg(packet.ip.daddr.byte4);
        conteoIPsDestino[ipDestino]++;
    }

    // 2. Calcular el promedio de longitud por protocolo
    double promedioTCP = totalTCP > 0 ? sumaLongitudTCP / totalTCP : 0;
    double promedioUDP = totalUDP > 0 ? sumaLongitudUDP / totalUDP : 0;
    double promedioOtros = totalOtros > 0 ? sumaLongitudOtros / totalOtros : 0;

    // 3. Calcular el porcentaje de paquetes por protocolo
    double porcentajeTCP = (double)totalTCP / totalPaquetes * 100;
    double porcentajeUDP = (double)totalUDP / totalPaquetes * 100;
    double porcentajeOtros = (double)totalOtros / totalPaquetes * 100;

    // 4. Encontrar la IP destino más frecuente
    QString ipDestinoFrecuente;
    int maxFrecuencia = 0;
    for (auto it = conteoIPsDestino.begin(); it != conteoIPsDestino.end(); ++it) {
        if (it.value() > maxFrecuencia) {
            maxFrecuencia = it.value();
            ipDestinoFrecuente = it.key();
        }
    }

    // 5. Mostrar estadísticas en una ventana emergente
    QString mensaje = QString(
                          "Estadísticas de Captura:\n\n"
                          "Total de Paquetes: %1\n\n"
                          "Porcentaje de Paquetes:\n"
                          "  - TCP: %2% (%3 paquetes)\n"
                          "  - UDP: %4% (%5 paquetes)\n"
                          "  - Otros: %6% (%7 paquetes)\n\n"
                          "Promedio de Longitud por Protocolo:\n"
                          "  - TCP: %8 bytes\n"
                          "  - UDP: %9 bytes\n"
                          "  - Otros: %10 bytes\n\n"
                          "IP Destino Más Frecuente: %11 (%12 veces)\n\n"
                          "Paquete Más Grande: %13 bytes"
                          )
                          .arg(totalPaquetes)
                          .arg(porcentajeTCP, 0, 'f', 2).arg(totalTCP)
                          .arg(porcentajeUDP, 0, 'f', 2).arg(totalUDP)
                          .arg(porcentajeOtros, 0, 'f', 2).arg(totalOtros)
                          .arg(promedioTCP, 0, 'f', 2)
                          .arg(promedioUDP, 0, 'f', 2)
                          .arg(promedioOtros, 0, 'f', 2)
                          .arg(ipDestinoFrecuente).arg(maxFrecuencia)
                          .arg(paqueteMaximo);

    QMessageBox::information(this, "Estadísticas de Captura", mensaje);
}

void menu_program::abrirPaginaWeb() {
    QUrl url("https://github.com/starcrash16/Sniffalant");
    if (!QDesktopServices::openUrl(url)) {
        qWarning() << "Error al intentar abrir la URL:" << url.toString();
    }
}

