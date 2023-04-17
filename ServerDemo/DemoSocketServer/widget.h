#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QVector>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void sendWelcome();
    void sendDataToClients(QString dataFromClient);

public slots:
    void handleNewConnection();
    void checkDataFromServerAndSend();
    void on_pushButton_2_clicked();
    void socketDisconnected();
    void handleConnectionError(QAbstractSocket::SocketError);
    void handleSocketError(QAbstractSocket::SocketError errorCode);

private:
    Ui::Widget *ui;

    QTcpServer* server;
    QVector<QTcpSocket*> socketList;

    int numOfConnection;
};
#endif // WIDGET_H
