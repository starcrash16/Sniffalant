#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "menu_program.h"
//pcap
#include <pcap/Winsock2.h>
#include <tchar.h>
#include <pcap/pcap.h>       // Librería de pcap
#include <winsock2.h>   // Para funciones de red en Windows - // Para ntohs y tipos de datos de red
#include <ws2tcpip.h>   // Funciones adicionales para sockets
#include <stdint.h>     // Tipos de datos estándar
#include <iostream>     // Para salida en consola
#include <string>       // Para manejo de cadenas
#include <ctime>        // Para formatear fechas y horas
#include <tchar.h>
#include <windows.h>


#include <QApplication>
#include <QListView>
#include <QStringListModel>
#include <QMessageBox>
//texto
#include <QTextStream>
//tiempo
#include <QTimer>
#include <QDesktopServices>
#include <QUrl>

#include <iostream>
using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    idDisp=1;
    ui->setupUi(this);  // Configuración de la UI
    setWindowTitle("Sniffalant");

    listaDisp();
}


//global
BOOL LoadNpcapDlls()
{
    _TCHAR npcap_dir[512];
    UINT len;
    len = GetSystemDirectory(npcap_dir, 480);
    if (!len) {
        fprintf(stderr, "Error in GetSystemDirectory: %x", GetLastError());
        return FALSE;
    }
    _tcscat_s(npcap_dir, 512, _T("\\Npcap"));
    if (SetDllDirectory(npcap_dir) == 0) {
        fprintf(stderr, "Error in SetDllDirectory: %x", GetLastError());
        return FALSE;
    }
    return TRUE;
}

void MainWindow::abrirPaginaWeb() {

}

//desctructor
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::listaDisp()
{
    vector<pair<string, string>> dispositivos; // Almacena {nombre interno, descripción}
    int i = 0;
    char errbuf[PCAP_ERRBUF_SIZE];

    /* Load Npcap and its functions. */
    if (!LoadNpcapDlls())
    {
        qWarning() << "No se pudo cargar Npcap.";
        return;
    }

    /* Retrieve the device list */
    if (pcap_findalldevs_ex(PCAP_SRC_IF_STRING, NULL, &alldevs, errbuf) == -1 || alldevs == nullptr)
    {
        qWarning() << "Error al obtener adaptadores: " << errbuf;
        return;
    }

    /* Populate the list of devices */
    listaD.clear();           // Limpiar el contenedor antes de llenarlo
    dispositivos.clear();     // Limpiar el contenedor antes de llenarlo
    i = 0;                // Asegúrate de inicializar el contador

    for (d = alldevs; d != NULL; d = d->next)
    {
        QString description = d->description ? QString::fromUtf8(d->description) : "No description available";
        QString name = QString::fromUtf8(d->name);

        qInfo() << QString("%1. %2 (%3)").arg(++i).arg(name).arg(description);

        dispositivos.emplace_back(name.toStdString(), description.toStdString());
        listaD << QString("%1. %2").arg(i).arg(description); // Solo mostramos descripción
    }


    /* Update the QListView with descriptions */
    QStringListModel *modelo = new QStringListModel(this);
    modelo->setStringList(listaD);
    ui->listView->setModel(modelo);

    /* Free the device list */

}


Ui::MainWindow *MainWindow::getUi() const
{

}

void MainWindow::setUi(Ui::MainWindow *newUi)
{

}

int MainWindow::getID()
{
    return idDisp;
}

void MainWindow::setID(int idDisp)
{
    idDisp=idDisp;
}


void MainWindow::on_listView_clicked(const QModelIndex &index)
{
    // Obtener el texto del elemento clicado
    QString dispositivo = index.data().toString();
    idDisp = index.row();
    setID(idDisp);
    qInfo() << "Dispositivo seleccionado :" << idDisp;

    // Mostrar un QMessageBox de confirmación
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,
                                  "Confirmar Adaptador",
                                  "¿Continuar con este adaptador? "
                                  "\nDispositivo: " + dispositivo,
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes)
    {
        // Crear la ventana menu_program con el QString
        menu_program *menuWindow = new menu_program(idDisp, alldevs, this);
        menuWindow->show();

        hide();
    }
    else
    {
        qInfo() << "Usuario seleccionó: No";
    }
}



void MainWindow::on_actionManual_de_Usuario_triggered()
{
    QUrl url("https://github.com/starcrash16/Sniffalant");
    if (!QDesktopServices::openUrl(url)) {
        qWarning() << "Error al intentar abrir la URL:" << url.toString();
    }
}

