#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                              ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    networkHandler = new NetworkHandler(this);
    networkHandler->startServer(6767);

    connect(networkHandler, &NetworkHandler::commandReceived, this, &MainWindow::processarComando);

    trens.resize(8);
    trens[1] = new Trem(1, 200, 50, &semaphoreVector);
    trens[2] = new Trem(2, 340, 50, &semaphoreVector);
    trens[3] = new Trem(3, 480, 50, &semaphoreVector);
    trens[4] = new Trem(4, 200, 200, &semaphoreVector);
    trens[5] = new Trem(5, 480, 200, &semaphoreVector);
    trens[6] = new Trem(6, 130, 300, &semaphoreVector);
    trens[7] = new Trem(7, 550, 300, &semaphoreVector);

    semaphoreVector.at(9).semaphore.acquire(1);
    semaphoreVector.at(8).semaphore.acquire(1);

    for (int i = 1; i <= 7; i++)
    {
        connect(trens[i], SIGNAL(updateGUI(int, int, int)), SLOT(updateInterface(int, int, int)));
        trens[i]->start();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

Trem *MainWindow::getTrem(int id)
{
    if (id >= 1 && id <= 7)
    {
        return trens[id];
    }
    return nullptr;
}

void MainWindow::processarComando(const ControlCommand &cmd)
{
    int delayCalculado = (100 - cmd.velocidade + 1) * 3;

    if (cmd.id == 0)
    {
        for (int i = 1; i <= 7; i++)
        {
            if (trens[i])
            {
                trens[i]->setVelocidade(delayCalculado);
                trens[i]->setEnable(cmd.enable);
            }
        }
    }
    else
    {
        Trem *t = getTrem(cmd.id);
        if (t)
        {
            t->setVelocidade(delayCalculado);
            t->setEnable(cmd.enable);
        }
    }
}

QLabel *MainWindow::getLabelTrem(int id)
{
    switch (id)
    {
    case 1:
        return ui->labelTrem01;
    case 2:
        return ui->labelTrem02;
    case 3:
        return ui->labelTrem03;
    case 4:
        return ui->labelTrem04;
    case 5:
        return ui->labelTrem05;
    case 6:
        return ui->labelTrem06;
    case 7:
        return ui->labelTrem07;
    default:
        return nullptr;
    }
}

void MainWindow::updateInterface(int id, int x, int y)
{
    QLabel *label = getLabelTrem(id);
    if (label)
    {
        label->setGeometry(x, y, 20, 20);
    }
}

