#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    client = new QTcpSocket(this);

    this->setWindowTitle("User chat");
    ui->lineEdit_2->setFocus();

    ui->comboBox->addItem("😀");
    ui->comboBox->addItem("😭");
    ui->comboBox->addItem("😈");
    ui->comboBox->addItem("👍");
    ui->comboBox->addItem("🌈");
    ui->comboBox->addItem("💓");
    ui->comboBox->addItem("💟");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_lineEdit_2_returnPressed()
{
    on_pushButton_2_clicked();
}

void Widget::on_pushButton_2_clicked()
{
    if(ui->lineEdit_2->text().isEmpty())
    {
        QMessageBox::warning(this,"Warning","Please input a name");
        ui->lineEdit_2->setFocus();
    }
    else
    {
        if(client->state() == QAbstractSocket::UnconnectedState)
        {
            client->abort();//abort k dừng mà ngát kết nối hiện có, có state r thì thôi cx đc.
            //có 2 kiểu KT: 1 là đã kết nối thì thôi, chưa kết nối thì kết nối; 2 là đã kết nối thì hủy kết nối r kết nối lại
            client->connectToHost(QHostAddress(ui->lineEdit_3->text()),ui->spinBox->text().toInt());

            ui->textEdit->append("Connecting...");

            connect(client,SIGNAL(connected()),this,SLOT(showConnected()));
            connect(client,SIGNAL(readyRead()),this,SLOT(handleComingData()));
            connect(client,SIGNAL(errorOccurred(QAbstractSocket::SocketError)),
                    this,SLOT(handleSocketError(QAbstractSocket::SocketError)));
            connect(client,SIGNAL(disconnected()),this,SLOT(disconnectedFromServer()));
        }
    }
}

void Widget::showConnected()
{
    ui->textEdit->append("You are connected. Start to chat");
    ui->pushButton_2->setEnabled(false);
    ui->textEdit->setReadOnly(false);
    ui->lineEdit_2->setReadOnly(true);

    QString welcomeYou="<b>" + ui->lineEdit_2->text() + "</b>" + " has joined the chat";
    QByteArray byteArrayWelcomeYou;
    QDataStream streamWelcomeYou(&byteArrayWelcomeYou,QIODevice::WriteOnly);
    streamWelcomeYou << welcomeYou;

    client->write(byteArrayWelcomeYou);
    client->flush();
}

void Widget::on_fontComboBox_currentFontChanged(const QFont &f)
{
    ui->pushButton->setFont(f);
    ui->textEdit->setFont(f);
}

void Widget::on_pushButton_4_clicked()
{
    QByteArray byteArrayFullData;//có thể biểu diễn mọi loại data vs QByteArray
    QDataStream streamFullData(&byteArrayFullData,QIODevice::WriteOnly);
    QString contentData = ui->comboBox->itemText(ui->comboBox->currentIndex());
    QString nickname = ui->lineEdit_2->text() + ": ";
    QString fullData = "<b>" + nickname + "</b>" + contentData;
    streamFullData << fullData;

    client->write(byteArrayFullData);
    client->flush();
    ui->lineEdit->setFocus();
}

void Widget::on_lineEdit_returnPressed()
{
    on_pushButton_clicked();
}

void Widget::on_pushButton_clicked()
{
    QString contentData = ui->lineEdit->text();
    QString nickname = ui->lineEdit_2->text() + ": ";
    QString fullData = "<b>" + nickname + "</b>" + contentData;

    QByteArray byteArrayFullData;
    QDataStream streamFullData(&byteArrayFullData,QIODevice::WriteOnly);
    streamFullData << fullData;

    client->write(byteArrayFullData);
    client->flush();

    ui->lineEdit->clear();
    ui->lineEdit->setFocus();
}

void Widget::handleComingData()
{
    QString strData;
    QDataStream streamComingData(client);
    streamComingData >> strData;

    ui->textEdit->append(strData);
}

void Widget::disconnectedFromServer()
{
    if(client->isOpen())
    {
        client->close();
        client->deleteLater();
    }

    this->close();
}

void Widget::on_pushButton_3_clicked()
{
    QString disconnectedString="<b>" + ui->lineEdit_2->text().toLocal8Bit() + "</b>" + " has disconnected";
    QByteArray byteArrayDisconnected;
    QDataStream streamDisconnected(&byteArrayDisconnected,QIODevice::WriteOnly);
    streamDisconnected << disconnectedString;

    client->write(byteArrayDisconnected);
    client->flush();
    client->close();
    client->deleteLater();

    this->close();
}

void Widget::handleSocketError(QAbstractSocket::SocketError errorCode)
{
    ui->textEdit->append("Error Occurred! Error code: " + QString::number(errorCode));
}
