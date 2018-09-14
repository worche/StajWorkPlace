#include "lsocket.h"

LSocket::LSocket(const QString hostAddress,int portNumber,QObject *parent) : QObject(parent), m_nNextBlockSize(0)
{
             status = false;

             host = hostAddress;
             port = portNumber;

             tcpSocket = new QTcpSocket(this);
             connect(tcpSocket, &QTcpSocket::disconnected, this, &LSocket::closeConnection);

             timeoutTimer = new QTimer();
             timeoutTimer->setSingleShot(true);
             connect(timeoutTimer, &QTimer::timeout, this, &LSocket::connectionTimeout);
}

void LSocket::connect2host()
{
              timeoutTimer->start(3000);
              tcpSocket->connectToHost(host, port);
              connect(tcpSocket, &QTcpSocket::connected, this, &LSocket::connected);
              connect(tcpSocket, &QTcpSocket::readyRead, this, &LSocket::readyRead);
}

void LSocket::connectionTimeout()
{
              if(tcpSocket->state() == QAbstractSocket::ConnectingState)
                 {
                         tcpSocket->abort();
                         emit tcpSocket->error(QAbstractSocket::SocketTimeoutError);
                 }
}
void LSocket::connected()
{                status = true;
                emit statusChanged(status);
}

void LSocket::readyRead()
{
            QDataStream in(tcpSocket);
               for (;;)
                     {
                         if (!m_nNextBlockSize)
                         {
                             if (tcpSocket->bytesAvailable() < sizeof(quint16)) { break; }
                             in >> m_nNextBlockSize;
                         }

                         if (tcpSocket->bytesAvailable() < m_nNextBlockSize) { break; }

                         QString str; in >> str;

                         if (str == "0")
                         {
                             str = "Connection closed";
                             closeConnection();
                         }

                         emit hasReadSome(str);
                         m_nNextBlockSize = 0;
                     }
}

void LSocket::closeConnection()
{
    timeoutTimer->stop();

           disconnect(tcpSocket, &QTcpSocket::connected, 0, 0);
           disconnect(tcpSocket, &QTcpSocket::readyRead, 0, 0);

           bool shouldEmit = false;
           switch (tcpSocket->state())
           {
           case 0:
               tcpSocket->disconnectFromHost();
                shouldEmit = true;
                break;
           case 2:
                 tcpSocket->abort();
                 shouldEmit = true;
                 break;
            default:
                 tcpSocket->abort();
            }

            if (shouldEmit)
            {
                status = false;
                emit statusChanged(status);
    }
}
bool LSocket::getStatus() {return status;}
