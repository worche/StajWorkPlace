#ifndef LSERVER_H
#define LSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>
#include <QDataStream>

class LServer : public QObject
{
    Q_OBJECT
public:
    explicit LServer(QObject *parent = 0);
    QTcpServer *tcpServer;
    QTcpSocket *clientSocket;
     QList<QTcpSocket *> getClients();

signals:
        void gotNewMesssage(QString msg);
       void smbDisconnected();

public slots:
       void newConnection();
       void readClient();
       void gotDisconnection();
   qint64 sendToClient(QTcpSocket *socket, const QString &str);
private:
   quint16 m_nNextBlockSize;
   QList<QTcpSocket*> clients;

};

#endif // LSERVER_H
