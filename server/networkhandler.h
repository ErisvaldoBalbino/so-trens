#ifndef NETWORKHANDLER_H
#define NETWORKHANDLER_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

struct ControlCommand
{
    int id;
    int velocidade;
    bool enable;
    ControlCommand() : id(0), velocidade(0), enable(true) {}
};

class NetworkHandler : public QTcpServer
{
    Q_OBJECT
public:
    explicit NetworkHandler(QObject *parent = nullptr);
    void startServer(int port);

signals:
    void commandReceived(ControlCommand cmd);

public slots:
    void onNewConnection();
};

#endif // NETWORKHANDLER_H

