#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lserver.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    server = new LServer(this);
       connect(server, &LServer::gotNewMesssage,
               this, &MainWindow::gotNewMesssage);
       connect(server->tcpServer, &QTcpServer::newConnection,
               this, &MainWindow::smbConnectedToServer);
       connect(server, &LServer::smbDisconnected,
   this, &MainWindow::smbDisconnectedFromServer);

}

MainWindow::~MainWindow()
{
    delete server;
   delete ui;
}


void MainWindow::on_disconnectButton_clicked()
{
    if(server->tcpServer->isListening())
       {
           disconnect(server->tcpServer, &QTcpServer::newConnection, server, &LServer::newConnection);

           QList<QTcpSocket *> clients = server->getClients();
           for(int i = 0; i < clients.count(); i++)
           {

               server->sendToClient(clients.at(i), "0");
                ui->ServerInfo->append(tr("<b>Server stopped</b>, post is closed"));
           }

           server->tcpServer->close();
           ui->ServerInfo->append(tr("<b>Error!</b> Server was not running"));
       }
       else
       {
   }

}

void MainWindow::smbConnectedToServer()
{
    ui->ServerInfo->append(tr("Somebody has connected"));
}

void MainWindow::smbDisconnectedFromServer()
{
    ui->ServerInfo->append(tr("Somebody has disconnected"));
}

void MainWindow::gotNewMesssage(QString msg)
{
    ui->ServerInfo->append(QString("New message: %1").arg(msg));
}

void MainWindow::on_testConnectB_clicked()
{
    if(server->tcpServer->isListening())
        {
            ui->ServerInfo->append(
                        QString("%1 %2")
                        .arg("Server is listening, number of connected clients:")
                        .arg(QString::number(server->getClients().count()))
                        );
        }
        else
        {
            ui->ServerInfo->append(
                        QString("%1 %2")
                        .arg("Server is not listening, number of connected clients:")
                        .arg(QString::number(server->getClients().count()))
                        );
    }
}

void MainWindow::on_connectButton_clicked()
{
    if (!server->tcpServer->listen(QHostAddress::Any, 12345))
    {
        ui->ServerInfo->append(tr("<font color=\"red\"><b>Error!</b> The port is taken by some other service.</font>"));
            return;
        }
        connect(server->tcpServer, &QTcpServer::newConnection, server, &LServer::newConnection);

        ui->ServerInfo->append(tr("<font color=\"green\"><b>Server started</b>, port is openned.</font>"));
}
