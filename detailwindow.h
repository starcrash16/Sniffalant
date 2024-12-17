#ifndef DETAILWINDOW_H
#define DETAILWINDOW_H

#include <QMainWindow>
#include <QObject>

namespace Ui { class DetailWindow; }

class DetailWindow
{
    Q_OBJECT
public:
    explicit DetailWindow(const QString &deviceName, QWidget *parent = nullptr); ~DetailWindow();

private:
    Ui::DetailWindow *ui;
    QString deviceName;

};

#endif // DETAILWINDOW_H
