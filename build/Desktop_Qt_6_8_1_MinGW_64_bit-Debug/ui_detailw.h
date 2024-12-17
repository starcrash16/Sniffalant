/********************************************************************************
** Form generated from reading UI file 'detailw.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETAILW_H
#define UI_DETAILW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_DetailW
{
public:
    QLabel *label_capturando;
    QTableWidget *tableWidget;

    void setupUi(QDialog *DetailW)
    {
        if (DetailW->objectName().isEmpty())
            DetailW->setObjectName("DetailW");
        DetailW->resize(1325, 684);
        label_capturando = new QLabel(DetailW);
        label_capturando->setObjectName("label_capturando");
        label_capturando->setGeometry(QRect(40, 40, 461, 20));
        tableWidget = new QTableWidget(DetailW);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(60, 110, 1051, 192));

        retranslateUi(DetailW);

        QMetaObject::connectSlotsByName(DetailW);
    } // setupUi

    void retranslateUi(QDialog *DetailW)
    {
        DetailW->setWindowTitle(QCoreApplication::translate("DetailW", "Dialog", nullptr));
        label_capturando->setText(QCoreApplication::translate("DetailW", "Capturando trafico de ....", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DetailW: public Ui_DetailW {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETAILW_H
