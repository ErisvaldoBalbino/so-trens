#ifndef CONTROLWINDOW_H
#define CONTROLWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class ControlWindow;
}
QT_END_NAMESPACE

class ControlWindow : public QMainWindow
{
    Q_OBJECT

public:
    ControlWindow(QWidget *parent = nullptr);
    ~ControlWindow();

private slots:
    void on_btnTrainOn_clicked();
    void on_btnTrainOff_clicked();
    void on_sliderSpeed_valueChanged(int value);
    void on_lineTrainId_textChanged(const QString &text);

    void onConnected();
    void onDisconnected();
    void onReadyRead();
    void onError(QAbstractSocket::SocketError);

private:
    Ui::ControlWindow *ui;
    QTcpSocket *socket;

    void enviarComando(int id, int velocidade, bool enable);
    void sendJson(const QJsonObject &jsonObj);
};

#endif // CONTROLWINDOW_H

