#ifndef MENU_PROGRAM_H
#define MENU_PROGRAM_H

#include <QMainWindow>
#include <QTableView>
#include <QStandardItemModel>
#include <QScrollArea>
#include <QPlainTextEdit>
#include <QFormLayout>
#include <QLabel>
#include <pcap/pcap.h>
#include "pcapworker.h"
#include <QThread>
#include <ui_menu_program.h>
#include <iostream>
#include <string.h>
#include <String>
#include <QDesktopServices>
#include <QUrl>
namespace Ui {
class menu_program;
}

class menu_program : public QMainWindow
{
    Q_OBJECT

public:
    explicit menu_program(int idDisp, pcap_if_t *alldevs, QWidget *parent = nullptr);
    ~menu_program();
    QString protocolActualFilter="";
    pcap_if_t *dispositivoSeleccionado;
    void detenerCiclo();
protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void agregarPaquete(const QList<QStandardItem*> &fila);

    void on_tableView_clicked(const QModelIndex &index);
    void on_btnUDP_clicked();
    void on_btnTCP_clicked();
    void on_btnOtros_clicked();
    void on_btnLimpiarF_clicked();
    void mostrarEstadisticas();
    void abrirPaginaWeb(); // Slot para abrir la página web
    //void detenerCiclo();
    void finalizarCaptura();




private:
    Ui::menu_program *ui;
    pcap_t *adhandle;
    QThread *workerThread;
    PcapWorker *worker;
    QStandardItemModel *model;

    QWidget *centralWidgetContainer;
    QVBoxLayout *mainLayout;

    // Arriba: Tabla
    // Abajo: 2 QScrollArea lado a lado
    QHBoxLayout *bottomLayout;
    QScrollArea *structuredArea;
    QScrollArea *rawArea;

    QWidget *structuredContainer;
    QFormLayout *structuredLayout;
    QPlainTextEdit *rawTextEdit;

    void iniciarCaptura();
    void mostrarDetallesPaquete(const QModelIndex &index);
    void exportarCSV(); // Método para exportar a CSV

    QString definir_Filtro();
    bool capturaCorriendo = false; // bandera para saber si estamos capturando

};

#endif // MENU_PROGRAM_H
