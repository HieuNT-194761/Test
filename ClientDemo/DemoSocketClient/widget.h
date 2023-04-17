#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QHostAddress>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_lineEdit_2_returnPressed();
    void on_pushButton_2_clicked();
    void showConnected();

    void on_fontComboBox_currentFontChanged(const QFont &f);
    void on_pushButton_4_clicked();
    void on_lineEdit_returnPressed();
    void on_pushButton_clicked();
    void handleComingData();

    void disconnectedFromServer();
    void on_pushButton_3_clicked();
    void handleSocketError(QAbstractSocket::SocketError erroeCode);

private:
    Ui::Widget *ui;
    QTcpSocket* client;
};
#endif // WIDGET_H
