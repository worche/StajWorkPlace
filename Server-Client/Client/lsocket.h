#ifndef LSOCKET_H
#define LSOCKET_H

#include <QObject>
#include "QTcpSocket"
#include <QTimer>
#include <QDataStream>

class LSocket : public QObject
{
    Q_OBJECT

public:
    LSocket(const QString hostAddress, int portVal, QObject *parent = 0);

    QTcpSocket *tcpSocket;
    QTcpSocket *clientSocket;

    bool getStatus();

public slots:
    void closeConnection();
    void connect2host();

signals:
    void statusChanged(bool);
    void hasReadSome(QString msg);

private slots:
    void readyRead();
    void connected();
    void connectionTimeout();

private:
    QString host;
    int port;
    bool status;
    quint16 m_nNextBlockSize;
QTimer *timeoutTimer;

};
#endif // LSOCKET_H
