/********************************************************************************
** Form generated from reading UI file 'menu_program.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_PROGRAM_H
#define UI_MENU_PROGRAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_menu_program
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QTableView *tableView;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QFrame *frame;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *menu_program)
    {
        if (menu_program->objectName().isEmpty())
            menu_program->setObjectName("menu_program");
        menu_program->resize(1097, 739);
        centralwidget = new QWidget(menu_program);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 70, 101, 41));
        label->setAutoFillBackground(true);
        label->setMargin(4);
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 140, 1051, 331));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(10, 480, 511, 201));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 509, 199));
        scrollArea->setWidget(scrollAreaWidgetContents);
        scrollArea_2 = new QScrollArea(centralwidget);
        scrollArea_2->setObjectName("scrollArea_2");
        scrollArea_2->setGeometry(QRect(540, 480, 521, 201));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 519, 199));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(120, 50, 211, 80));
        frame->setAutoFillBackground(false);
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        pushButton = new QPushButton(frame);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 10, 75, 24));
        pushButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(110, 10, 75, 24));
        pushButton_2->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_3 = new QPushButton(frame);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(10, 40, 75, 24));
        pushButton_3->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 0, 411, 41));
        menu_program->setCentralWidget(centralwidget);
        menubar = new QMenuBar(menu_program);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1097, 26));
        menu_program->setMenuBar(menubar);
        statusbar = new QStatusBar(menu_program);
        statusbar->setObjectName("statusbar");
        menu_program->setStatusBar(statusbar);

        retranslateUi(menu_program);

        QMetaObject::connectSlotsByName(menu_program);
    } // setupUi

    void retranslateUi(QMainWindow *menu_program)
    {
        menu_program->setWindowTitle(QCoreApplication::translate("menu_program", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("menu_program", "Filtros de Paquetes", nullptr));
        pushButton->setText(QCoreApplication::translate("menu_program", "UDP", nullptr));
        pushButton_2->setText(QCoreApplication::translate("menu_program", "TCP", nullptr));
        pushButton_3->setText(QCoreApplication::translate("menu_program", "Otros", nullptr));
        label_2->setText(QCoreApplication::translate("menu_program", "Filtros de Paquetes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class menu_program: public Ui_menu_program {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_PROGRAM_H
