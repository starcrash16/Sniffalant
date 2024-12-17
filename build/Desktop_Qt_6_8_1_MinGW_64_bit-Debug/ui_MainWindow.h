/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionManual_de_Usuario;
    QAction *actionPDF;
    QAction *actionEXCELL;
    QWidget *centralwidget;
    QListView *listView;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_10;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuAyuda;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionManual_de_Usuario = new QAction(MainWindow);
        actionManual_de_Usuario->setObjectName("actionManual_de_Usuario");
        actionManual_de_Usuario->setCheckable(true);
        actionPDF = new QAction(MainWindow);
        actionPDF->setObjectName("actionPDF");
        actionEXCELL = new QAction(MainWindow);
        actionEXCELL->setObjectName("actionEXCELL");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        listView = new QListView(centralwidget);
        listView->setObjectName("listView");
        listView->setGeometry(QRect(80, 180, 651, 192));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(280, 10, 281, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("MS Sans Serif")});
        font.setPointSize(14);
        font.setItalic(true);
        label_3->setFont(font);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(260, 140, 311, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("MS Sans Serif")});
        font1.setPointSize(12);
        font1.setItalic(true);
        label_4->setFont(font1);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(350, 70, 111, 71));
        label->setPixmap(QPixmap(QString::fromUtf8("Sniffalant_big.png")));
        label->setScaledContents(true);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(320, 450, 191, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("MS Sans Serif")});
        font2.setPointSize(8);
        font2.setItalic(true);
        label_5->setFont(font2);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(300, 40, 211, 31));
        label_6->setFont(font2);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(330, 510, 181, 31));
        label_8->setFont(font2);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(320, 420, 211, 31));
        label_7->setFont(font2);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(320, 480, 201, 31));
        label_9->setFont(font2);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(340, 390, 151, 31));
        label_10->setFont(font);
        label_10->setScaledContents(true);
        MainWindow->setCentralWidget(centralwidget);
        listView->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        label_8->raise();
        label_7->raise();
        label_9->raise();
        label_10->raise();
        label->raise();
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menuAyuda = new QMenu(menubar);
        menuAyuda->setObjectName("menuAyuda");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuAyuda->menuAction());
        menuAyuda->addSeparator();
        menuAyuda->addAction(actionManual_de_Usuario);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionManual_de_Usuario->setText(QCoreApplication::translate("MainWindow", "Manual de Usuario", nullptr));
        actionPDF->setText(QCoreApplication::translate("MainWindow", "Archivo PDF", nullptr));
        actionEXCELL->setText(QCoreApplication::translate("MainWindow", "Archiuvo EXCELL", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Bienvenido a Sniffalant", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Selecciona un Dispositivo de Red", nullptr));
        label->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "De Anda Medina Ren\303\251  Rosendo", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Analizador de Paquetes de la Red", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Saucedo Diaz Valeria Michelle ", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Morquecho Canales Ernesto Alonso ", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Gonzalez Rivera Diana Esmeralda ", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Realizado por:", nullptr));
        menuAyuda->setTitle(QCoreApplication::translate("MainWindow", "Ayuda", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
