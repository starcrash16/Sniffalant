#include "detailwindow.h"


DetailWindow::DetailWindow(const QString &deviceName, QWidget *parent) : QMainWindow(parent), ui(new Ui::DetailWindow), deviceName(deviceName)
{ ui->setupUi(this);
    // Mostrar el nombre del dispositivo en un label, por ejemplo
    ui->labelDeviceName->setText("Dispositivo: " + deviceName);
}

DetailWindow::~DetailWindow() { delete ui; }
