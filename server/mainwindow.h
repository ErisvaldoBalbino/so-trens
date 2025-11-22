#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qlabel.h"
#include "trem.h"
#include "networkhandler.h"
#include <QMainWindow>
#include <QSemaphore>
#include <QVector>

using namespace std;

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void updateInterface(int, int, int);

private:
    Ui::MainWindow *ui;

    NetworkHandler *networkHandler;
    QVector<Trem*> trens;
    QVector<BinarySemaphoreWrapper> semaphoreVector{10};

    Trem *getTrem(int id);
    QLabel *getLabelTrem(int id);
    void processarComando(const ControlCommand &cmd);
};

#endif // MAINWINDOW_H

