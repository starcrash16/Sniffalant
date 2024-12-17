/********************************************************************************
** Form generated from reading UI file 'portadaproy.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PORTADAPROY_H
#define UI_PORTADAPROY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PortadaProy
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_8;
    QPushButton *pushButton;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PortadaProy)
    {
        if (PortadaProy->objectName().isEmpty())
            PortadaProy->setObjectName("PortadaProy");
        PortadaProy->resize(800, 600);
        centralwidget = new QWidget(PortadaProy);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(200, 40, 351, 221));
        label->setScaledContents(true);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(230, 420, 351, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("MS Sans Serif")});
        font.setPointSize(12);
        font.setItalic(true);
        label_5->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(260, 320, 251, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("MS Sans Serif")});
        font1.setPointSize(14);
        font1.setItalic(true);
        label_3->setFont(font1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(240, 250, 291, 71));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("MS Sans Serif")});
        font2.setPointSize(28);
        font2.setItalic(true);
        label_2->setFont(font2);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(240, 480, 351, 31));
        label_8->setFont(font);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(320, 520, 141, 29));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(220, 390, 331, 31));
        label_6->setFont(font);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(220, 450, 351, 31));
        label_7->setFont(font);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(310, 360, 181, 31));
        label_4->setFont(font1);
        PortadaProy->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PortadaProy);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        PortadaProy->setMenuBar(menubar);
        statusbar = new QStatusBar(PortadaProy);
        statusbar->setObjectName("statusbar");
        PortadaProy->setStatusBar(statusbar);

        retranslateUi(PortadaProy);

        QMetaObject::connectSlotsByName(PortadaProy);
    } // setupUi

    void retranslateUi(QMainWindow *PortadaProy)
    {
        PortadaProy->setWindowTitle(QCoreApplication::translate("PortadaProy", "MainWindow", nullptr));
        label->setText(QString());
        label_5->setText(QCoreApplication::translate("PortadaProy", "De Anda Medina Ren\303\251  Rosendo", nullptr));
        label_3->setText(QCoreApplication::translate("PortadaProy", "Analizador de Paquetes de la Red", nullptr));
        label_2->setText(QCoreApplication::translate("PortadaProy", "SNIFFALANT", nullptr));
        label_8->setText(QCoreApplication::translate("PortadaProy", "Saucedo Diaz Valeria Michelle ", nullptr));
        pushButton->setText(QCoreApplication::translate("PortadaProy", "Iniciar Programa", nullptr));
        label_6->setText(QCoreApplication::translate("PortadaProy", "Morquecho Canales Ernesto Alonso ", nullptr));
        label_7->setText(QCoreApplication::translate("PortadaProy", "Gonzalez Rivera Diana Esmeralda ", nullptr));
        label_4->setText(QCoreApplication::translate("PortadaProy", "Realizado por:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PortadaProy: public Ui_PortadaProy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PORTADAPROY_H
