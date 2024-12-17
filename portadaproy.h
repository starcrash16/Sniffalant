#ifndef PORTADAPROY_H
#define PORTADAPROY_H

#include <QMainWindow>
#include <QLabel>
#include <QPixmap>
#include <QScreen>
#include <QGuiApplication>
namespace Ui {
class PortadaProy;
}

class PortadaProy : public QMainWindow
{
    Q_OBJECT

public:
    explicit PortadaProy(QWidget *parent = nullptr);
    ~PortadaProy();
    void mostrarImagen(); // Método para mostrar la imagen

private:
    Ui::PortadaProy *ui;
    QLabel *imagenLabel; // QLabel para la imagen


};

#endif // PORTADAPROY_H
