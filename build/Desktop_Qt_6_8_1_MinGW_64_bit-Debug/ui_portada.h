/********************************************************************************
** Form generated from reading UI file 'portada.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PORTADA_H
#define UI_PORTADA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *pushButton;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(250, 220, 291, 71));
        QFont font;
        font.setFamilies({QString::fromUtf8("MS Sans Serif")});
        font.setPointSize(28);
        font.setItalic(true);
        label_2->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(270, 290, 251, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("MS Sans Serif")});
        font1.setPointSize(14);
        font1.setItalic(true);
        label_3->setFont(font1);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(320, 320, 151, 31));
        label_4->setFont(font1);
        label_4->setScaledContents(true);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(250, 390, 301, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("MS Sans Serif")});
        font2.setPointSize(12);
        font2.setItalic(true);
        label_5->setFont(font2);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(240, 360, 331, 31));
        label_6->setFont(font2);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(240, 420, 311, 31));
        label_7->setFont(font2);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(260, 450, 281, 31));
        label_8->setFont(font2);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(320, 500, 141, 29));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(260, 30, 261, 191));
        label->setPixmap(QPixmap(QString::fromUtf8("Sniffalant_big.png")));
        label->setScaledContents(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Sniffalant", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "SNIFFALANT", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Analizador de Paquetes de la Red", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Realizado por:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "De Anda Medina Ren\303\251  Rosendo", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Morquecho Canales Ernesto Alonso ", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Gonzalez Rivera Diana Esmeralda ", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Saucedo Diaz Valeria Michelle ", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Iniciar Programa", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PORTADA_H
