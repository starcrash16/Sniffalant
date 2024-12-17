/********************************************************************************
** Form generated from reading UI file 'menu_devices.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_DEVICES_H
#define UI_MENU_DEVICES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
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
    QLabel *labelWD;
    QPushButton *pushButton;
    QListView *listView;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuAyuda;
    QMenu *menuExportar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionManual_de_Usuario = new QAction(MainWindow);
        actionManual_de_Usuario->setObjectName("actionManual_de_Usuario");
        actionPDF = new QAction(MainWindow);
        actionPDF->setObjectName("actionPDF");
        actionEXCELL = new QAction(MainWindow);
        actionEXCELL->setObjectName("actionEXCELL");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        labelWD = new QLabel(centralwidget);
        labelWD->setObjectName("labelWD");
        labelWD->setGeometry(QRect(70, 150, 181, 20));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(80, 180, 83, 29));
        listView = new QListView(centralwidget);
        listView->setObjectName("listView");
        listView->setGeometry(QRect(80, 230, 651, 192));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menuAyuda = new QMenu(menubar);
        menuAyuda->setObjectName("menuAyuda");
        menuExportar = new QMenu(menubar);
        menuExportar->setObjectName("menuExportar");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuAyuda->menuAction());
        menubar->addAction(menuExportar->menuAction());
        menuAyuda->addSeparator();
        menuAyuda->addAction(actionManual_de_Usuario);
        menuExportar->addAction(actionPDF);
        menuExportar->addAction(actionEXCELL);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionManual_de_Usuario->setText(QCoreApplication::translate("MainWindow", "Manual de Usuario", nullptr));
        actionPDF->setText(QCoreApplication::translate("MainWindow", "Archivo PDF", nullptr));
        actionEXCELL->setText(QCoreApplication::translate("MainWindow", "Archiuvo EXCELL", nullptr));
        labelWD->setText(QCoreApplication::translate("MainWindow", "Welcome to Wire Duck", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Capturar", nullptr));
        menuAyuda->setTitle(QCoreApplication::translate("MainWindow", "Ayuda", nullptr));
        menuExportar->setTitle(QCoreApplication::translate("MainWindow", "Exportar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_DEVICES_H
