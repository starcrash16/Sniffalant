#include "portadaproy.h"
#include "ui_portadaproy.h"
#include <QLabel>
#include <QPixmap>
#include <QScreen>
#include <QGuiApplication>


PortadaProy::PortadaProy(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PortadaProy)
{

    ui->setupUi(this);
}

PortadaProy::~PortadaProy()
{
    delete ui;
}

void PortadaProy::mostrarImagen() {
    // 1. Crear QLabel para la imagen
    imagenLabel = new QLabel(this);

    // 2. Cargar la imagen con QPixmap
    QPixmap pixmap("Sniffalant_big.png");
    if (pixmap.isNull()) {
        qWarning() << "Error: No se pudo cargar la imagen.";
        return;
    }

    // 3. Obtener las dimensiones de la pantalla
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int screenWidth = screenGeometry.width();
    int screenHeight = screenGeometry.height();

    // 4. Ajustar la imagen para que ocupe 1/4 de la altura de la pantalla
    int alturaDeseada = screenHeight / 4;

    // Escalar el QPixmap manteniendo el aspecto
    QPixmap scaledPixmap = pixmap.scaledToHeight(alturaDeseada, Qt::SmoothTransformation);

    // 5. Calcular la posición X para centrar la imagen
    int posicionX = (screenWidth - scaledPixmap.width()) / 2; // Centrado en X
    int posicionY = 10; // Margen desde la parte superior

    // 6. Configurar QLabel con el QPixmap escalado
    imagenLabel->setPixmap(scaledPixmap);
    imagenLabel->setAlignment(Qt::AlignCenter);
    imagenLabel->setGeometry(posicionX, posicionY, scaledPixmap.width(), alturaDeseada);

    // 7. Mostrar QLabel
    imagenLabel->show();
}
