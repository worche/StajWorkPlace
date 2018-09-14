#include "lserver.h"

LServer::LServer(QObject *parent) : QObject(parent)
{

        tcpServer = new QTcpServer(this);
        clientSocket = new QTcpSocket;
}


void LServer::newConnection(){
   clientSocket = tcpServer->nextPendingConnection();

        connect(clientSocket, &QTcpSocket::disconnected, clientSocket, &QTcpSocket::deleteLater);
        connect(clientSocket, &QTcpSocket::readyRead, this, &LServer::readClient);
        connect(clientSocket, &QTcpSocket::disconnected, this, &LServer::gotDisconnection);

        clients << clientSocket;

    sendToClient(clientSocket, "Reply: connection established");


}

QList<QTcpSocket *> LServer::getClients()
{
    return clients;
}

void LServer::readClient()
{

    clientSocket=qobject_cast<QTcpSocket*>(sender());

    emit gotNewMesssage(clientSocket->readAll());
}

void LServer::gotDisconnection()
{
    clients.removeAt(clients.indexOf((QTcpSocket*)sender()));
    emit smbDisconnected();
}

qint64 LServer::sendToClient(QTcpSocket* socket, const QString& str)
{
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out << quint16(0) << str;

    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));

    return socket->write(arrBlock);
}




