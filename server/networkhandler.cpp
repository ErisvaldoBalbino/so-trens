#include "networkhandler.h"

NetworkHandler::NetworkHandler(QObject *parent) : QTcpServer(parent)
{
    connect(this, &QTcpServer::newConnection, this, &NetworkHandler::onNewConnection);
}

void NetworkHandler::startServer(int port)
{
    this->listen(QHostAddress::Any, port);
}

void NetworkHandler::onNewConnection()
{
    QTcpSocket *client = nextPendingConnection();

    connect(client, &QTcpSocket::readyRead, this, [this, client]()
            {
        while (client->bytesAvailable()) {
            QByteArray data = client->readAll();
            QJsonDocument doc = QJsonDocument::fromJson(data);

            if (doc.isNull() || !doc.isObject()) {
                continue;
            }

            QJsonObject json = doc.object();
            ControlCommand cmd;
            cmd.id = json["id"].toInt(0);
            cmd.velocidade = json["velocidade"].toInt(1);
            cmd.enable = json["enable"].toBool(true);

            emit commandReceived(cmd);
        } });

    connect(client, &QTcpSocket::disconnected, client, &QTcpSocket::deleteLater);
}

