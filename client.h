#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QHostAddress>
#include <QTcpSocket>

class Client
{
public:
    Client(QString hostIP, quint16 hostPort);
    ~Client();

public:
    QTcpSocket *tcpSocket;
    QString getHostIP();
    void setHostIP();
    quint16 getPort();
    void setPort();

    void connect();

private:
    QHostAddress m_hostAddress;
    quint16 m_hostPort;
};

#endif // CLIENT_H
