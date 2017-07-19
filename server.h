#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QString>
#include <QHostAddress>

class Server
{
public:
    Server(QHostAddress hostIP, quint16 hostPort);

public:
    QHostAddress getHostAddress();
    void setHostAddress();
    quint16 getHostPort();
    void setHostPort();

    void attemptConnection();
    void connectionAccepted();

private:
    QHostAddress m_hostAddress;
    quint16 m_hostPort;

};

#endif // SERVER_H
