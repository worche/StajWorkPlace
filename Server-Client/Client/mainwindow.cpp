#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include "lsocket.h"
#include <QDataStream>
#include <QDataStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->pushButton_disconnect->setVisible(false);

    //ui->ipLineText->text() ui->port->value()
    client = new LSocket(ui->ipLineText->text(),ui->port->value());

    setStatus(client->getStatus());
    client = new LSocket(ui->ipLineText->text(),ui->port->value());
    connect(client, &LSocket::hasReadSome, this, &MainWindow::receivedSomething);
    connect(client, &LSocket::statusChanged, this, &MainWindow::setStatus);

    connect(client->tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(gotError(QAbstractSocket::SocketError)));

}

MainWindow::~MainWindow()
{
    delete client;
    delete ui;
}

void MainWindow::setStatus(bool newStatus)
{
    if(newStatus)
        {
            ui->status_label->setText(
                        tr("<font color=\"green\">CONNECTED</font>"));
            ui->status_label->setStyleSheet("QLabel { background-color : yellow;}");

            ui->pushButton_connect->setVisible(false);
            ui->pushButton_disconnect->setVisible(true);
            ui->ipLineText->setVisible(false);
            ui->label->setVisible(false);
            ui->port->setVisible(false);
        }
        else
        {
            ui->status_label->setText(
                    tr("<font color=\"red\">DISCONNECTED</font>"));
            ui->status_label->setStyleSheet("QLabel { background-color : yellow;}");
            ui->pushButton_connect->setVisible(true);
            ui->pushButton_disconnect->setVisible(false);
            ui->ipLineText->setVisible(true);
            ui->port->setVisible(true);
             ui->label->setVisible(true);
    }
}

void MainWindow::receivedSomething(QString msg)
{
     ui->textBrowser->append(msg);
}

void MainWindow::gotError(QAbstractSocket::SocketError err)
{
    QString strError = "unknown";
        switch (err)
        {
            case 0:
                strError = "Connection was refused";
                break;
            case 1:
                strError = "Remote host closed the connection";
                break;
            case 2:
                strError = "Host address was not found";
                break;
            case 5:
                strError = "Connection timed out";
                break;
            default:
                strError = "Unknown error";
        }

    ui->textBrowser->append(strError);
}

void MainWindow::on_pushButton_connect_clicked()
{

    client->connect2host();
}

void MainWindow::on_pushButton_send_clicked()
{
    QByteArray ba=ui->lineEdit->text().toUtf8();
   ui->lineEdit->text()="";
   qDebug()<<ba;


    client->tcpSocket->write(ba);
}

void MainWindow::on_pushButton_disconnect_clicked()
{
    client->closeConnection();
}
