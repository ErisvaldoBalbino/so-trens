#include "controlwindow.h"
#include "ui_controlwindow.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QTcpSocket>

ControlWindow::ControlWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::ControlWindow), socket(new QTcpSocket(this))
{
    ui->setupUi(this);

    connect(socket, &QTcpSocket::connected, this, &ControlWindow::onConnected);
    connect(socket, &QTcpSocket::disconnected, this, &ControlWindow::onDisconnected);
    connect(socket, &QTcpSocket::readyRead, this, &ControlWindow::onReadyRead);
    connect(socket, &QTcpSocket::errorOccurred, this, &ControlWindow::onError);

    socket->connectToHost("127.0.0.1", 1234);
}

ControlWindow::~ControlWindow()
{
    delete ui;
}

void ControlWindow::enviarComando(int id, int velocidade, bool enable)
{
    QJsonObject json;
    json["id"] = id;
    json["velocidade"] = velocidade;
    json["enable"] = enable;
    sendJson(json);
}

void ControlWindow::sendJson(const QJsonObject &jsonObj)
{
    if (socket->state() == QAbstractSocket::ConnectedState)
    {
        QJsonDocument doc(jsonObj);
        socket->write(doc.toJson(QJsonDocument::Compact));
        socket->flush();
    }
}

void ControlWindow::on_btnTrainOn_clicked()
{
    int id = ui->lineTrainId->text().toInt();
    enviarComando(id, ui->sliderSpeed->value(), true);
}

void ControlWindow::on_btnTrainOff_clicked()
{
    int id = ui->lineTrainId->text().toInt();
    enviarComando(id, 0, false);
}

void ControlWindow::on_sliderSpeed_valueChanged(int value)
{
    ui->labelSpeedValue->setText(QString::number(value));

    int id = ui->lineTrainId->text().toInt();
    if (id >= 0 && socket->state() == QAbstractSocket::ConnectedState)
    {
        enviarComando(id, value, true);
    }
}

void ControlWindow::onConnected()
{
}

void ControlWindow::onDisconnected()
{
}

void ControlWindow::onReadyRead()
{
    socket->readAll();
}

void ControlWindow::onError(QAbstractSocket::SocketError)
{
}

