#include "controlwindow.h"
#include "ui_controlwindow.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QTcpSocket>
#include <QIntValidator>

ControlWindow::ControlWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::ControlWindow), socket(new QTcpSocket(this))
{
    ui->setupUi(this);

    ui->btnTrainOn->setEnabled(false);
    ui->btnTrainOff->setEnabled(false);
    ui->sliderSpeed->setEnabled(false);
    ui->lineTrainId->setEnabled(false);

    QIntValidator *validator = new QIntValidator(0, 7, this);
    ui->lineTrainId->setValidator(validator);
    connect(ui->lineTrainId, &QLineEdit::textChanged, this, &ControlWindow::on_lineTrainId_textChanged);

    connect(socket, &QTcpSocket::connected, this, &ControlWindow::onConnected);
    connect(socket, &QTcpSocket::disconnected, this, &ControlWindow::onDisconnected);
    connect(socket, &QTcpSocket::readyRead, this, &ControlWindow::onReadyRead);
    connect(socket, &QTcpSocket::errorOccurred, this, &ControlWindow::onError);

    socket->connectToHost("127.0.0.1", 6767);
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
    QString idText = ui->lineTrainId->text().trimmed();
    int id = idText.isEmpty() ? 0 : idText.toInt();
    
    if (id < 0 || id > 7) {
        ui->lineTrainId->setStyleSheet("background-color: #5a3a3a; border: 2px solid #e74c3c; border-radius: 4px; padding: 4px; color: white;");
        return;
    }
    
    ui->lineTrainId->setStyleSheet("");
    enviarComando(id, ui->sliderSpeed->value(), true);
}

void ControlWindow::on_btnTrainOff_clicked()
{
    QString idText = ui->lineTrainId->text().trimmed();
    int id = idText.isEmpty() ? 0 : idText.toInt();
    
    if (id < 0 || id > 7) {
        ui->lineTrainId->setStyleSheet("background-color: #5a3a3a; border: 2px solid #e74c3c; border-radius: 4px; padding: 4px; color: white;");
        return;
    }
    
    ui->lineTrainId->setStyleSheet("");
    enviarComando(id, 0, false);
}

void ControlWindow::on_sliderSpeed_valueChanged(int value)
{
    ui->labelSpeedValue->setText(QString::number(value));

    QString idText = ui->lineTrainId->text().trimmed();
    int id = idText.isEmpty() ? 0 : idText.toInt();
    
    if (id >= 0 && id <= 7 && socket->state() == QAbstractSocket::ConnectedState)
    {
        enviarComando(id, value, true);
    }
}

void ControlWindow::onConnected()
{
    ui->label_connectionStatus->setText("Conectado");
    ui->label_connectionStatus->setStyleSheet("color: #2ecc71; font-weight: bold; font-size: 9px;");
    ui->btnTrainOn->setEnabled(true);
    ui->btnTrainOff->setEnabled(true);
    ui->sliderSpeed->setEnabled(true);
    ui->lineTrainId->setEnabled(true);
}

void ControlWindow::onDisconnected()
{
    ui->label_connectionStatus->setText("Desconectado");
    ui->label_connectionStatus->setStyleSheet("color: #e74c3c; font-weight: bold; font-size: 9px;");
    ui->btnTrainOn->setEnabled(false);
    ui->btnTrainOff->setEnabled(false);
    ui->sliderSpeed->setEnabled(false);
    ui->lineTrainId->setEnabled(false);
}

void ControlWindow::onReadyRead()
{
    socket->readAll();
}

void ControlWindow::onError(QAbstractSocket::SocketError error)
{
    Q_UNUSED(error);
    ui->label_connectionStatus->setText("Erro de Conexão");
    ui->label_connectionStatus->setStyleSheet("color: #e74c3c; font-weight: bold; font-size: 9px;");
    ui->btnTrainOn->setEnabled(false);
    ui->btnTrainOff->setEnabled(false);
    ui->sliderSpeed->setEnabled(false);
    ui->lineTrainId->setEnabled(false);
}

void ControlWindow::on_lineTrainId_textChanged(const QString &text)
{
    if (text.isEmpty() || text.toInt() >= 0) {
        ui->lineTrainId->setStyleSheet("");
    }
}

