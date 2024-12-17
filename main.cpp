#include "MainWindow.h"
#include "menu_program.h"
#include "portadaproy.h"
#include <QApplication>

using namespace std;

//estruct
MainWindow *w;


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    //MainWindow w;
    w = new MainWindow();
    w->setWindowTitle("Sniffalant");
    w->show();
    w->listaDisp();
    return a.exec();
}





/*
    w = new MainWindow();
    w->setWindowTitle("Sniffalant");
    w->show();
    w->listaDisp();
*/
