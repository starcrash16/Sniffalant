#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <vector>
#include <string.h>
//pcap
#include <pcap/pcap.h>
#include <winsock2.h>   // Para funciones de red en Windows - // Para ntohs y tipos de datos de red
#include <ws2tcpip.h>   // Funciones adicionales para sockets
#include <tchar.h>
#include <QDesktopServices>
#include <QUrl>
//otras ventanas



QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //cadenas
    QString nombreVentana;

    //variables tipo numerico


    //constructor y destructor
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //funciones hechas por mi
    void listaDisp(void);
    //funcion que capta los paquetes
    //static void packet_handler(u_char* param, const struct pcap_pkthdr* header, const u_char* pkt_data);

    Ui::MainWindow *getUi() const;
    void setUi(Ui::MainWindow *newUi);
    int getID();
    void setID(int idDisp);

signals:
    void idSeleccionado(int id);

private slots:
    void abrirPaginaWeb(); // Slot para abrir la página web
    void on_listView_clicked(const QModelIndex &index);
    //void onTimeout();

    void on_actionManual_de_Usuario_triggered();

private:
    Ui::MainWindow *ui;
    int idDisp;
    QStringList listaD;
    pcap_if_t* alldevs;
    pcap_if_t* d;
    //para mostrar la info de paquetes

};
#endif // MAINWINDOW_H
