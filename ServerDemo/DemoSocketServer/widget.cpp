#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    server = new QTcpServer();
    numOfConnection = 0;

    this->setWindowTitle("Server chat");

    if(!server->listen(QHostAddress::Any,6000))
    {
        qWarning() << "Server cannot listen! Error code:  " << server->serverError();//todo gom vào lỗi
    }
    connect(server,SIGNAL(newConnection()),this,SLOT(handleNewConnection()));
    connect(server,SIGNAL(acceptError(QAbstractSocket::SocketError)),this,SLOT(handleConnectionError(QAbstractSocket::SocketError)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handleNewConnection()
{
    ++ numOfConnection;
    QTcpSocket* socket = server->nextPendingConnection();

    socketList << socket;
    ui->label_2->setText("<h1 style='text-align:center;'><b>Number of people connecting: "
                         + QString::number(numOfConnection) + "</b></h1>");
    sendWelcome();

    connect(socket,SIGNAL(readyRead()),this,SLOT(checkDataFromServerAndSend()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(socketDisconnected()));
    connect(socket,SIGNAL(errorOccurred(QAbstractSocket::SocketError)),
            this,SLOT(handleSocketError(QAbstractSocket::SocketError)));
}

void Widget::sendWelcome()
{
    if(socketList.size() == 1)
    {
        sendDataToClients(QString("Welcome!"));
    }
}

void Widget::checkDataFromServerAndSend()
{
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());

    //    QByteArray dataFromClient = socket->readAll();
    QDataStream data(socket);
    QString dataFromClient;
    data >> dataFromClient;

    sendDataToClients(dataFromClient);
}

void Widget::sendDataToClients(QString dataFromClient)
{
    QByteArray byteArrayDataromClient;
    QDataStream streamDataFromClient(&byteArrayDataromClient,QIODevice::WriteOnly);
    streamDataFromClient << dataFromClient;

    for(int i=0;i<socketList.size();i++)
    {
        socketList[i]->write(byteArrayDataromClient);
        socketList[i]->flush();
    }
}

void Widget::on_pushButton_2_clicked()
{
    if(!socketList.isEmpty())
    {
        //                for(int i=0;i<socketList.size();++i)
        //                {
        //                            qDebug() << "2: " << socketList.size() << i <<  socketList.at(i)->isOpen();
        //                    if(socketList.at(i)->isOpen())
        //                    {
        //                                qDebug() << "3";
        //                        socketList.at(i)->close();
        //                        socketList.at(i)->deleteLater();
        //                        socketList.remove(i);
        //                    }
        //                }//cái gì của client thì để client tự xóa-> client phát signal đóng mà lại đóng tiếp là chết r
        //   để cái lỗi này lại cho nhớ->k nên dùng vòng for trong qt mà nên dùng foreach vì vs các class phức tạp sẽ HĐ sai
        foreach(QTcpSocket* socket, socketList)
        {
            qDebug() << "2: " << socketList.size();
            socket->close();
            socket->deleteLater();
            socketList.removeOne(socket);
        }
        socketList.clear();//chả cần clear nx or clear ở đây bỏ trên cx đc
    }
    server->close();
    this->close();
}

void Widget::socketDisconnected()
{
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
    //    socket->close();=>trap chủ động xóa thì ok chứ close là hỏng-> vì đã close r gọi close tiếp là lỗi
    //=>trc khi close thì kiểm tra xem có open k, trc khi xóa kiểm tra xem có tồn tại k với if sẽ chuẩn hơn.
    socket->deleteLater();
    socketList.removeOne(socket);
    numOfConnection --;
    ui->label_2->setText("<h1 style='text-align:center;'><b>Number of people connecting: "
                         + QString::number(numOfConnection) + "</b></h1>");
}

void Widget::handleConnectionError(QAbstractSocket::SocketError errorCode)
{
    qDebug() << "Server connection Error! Error code:  " << errorCode;
    sendDataToClients("Server connection Error! Error code:  " + QByteArray::number(errorCode));
}

void Widget::handleSocketError(QAbstractSocket::SocketError errorCode)
{
    qDebug() << "Socket Error Code: " << errorCode;
}

//hướng phát triển: dùng threadpool+runnable+incomingEvent để dùng multi gửi tin nhắn cùng lúc.
//Cái này nếu gửi cùng lúc có thể deadlock đấy
