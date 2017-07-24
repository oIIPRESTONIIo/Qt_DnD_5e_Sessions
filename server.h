#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QString>
#include <QHostAddress>

class Server : public QObject
{

    Q_OBJECT
public:
    Server(QHostAddress hostIP, quint16 hostPort);
    explicit Server(QObject *parent = 0);
    ~Server();

signals:

public slots:
    void newConnection();

private:
    QTcpServer *server;

public:
    //QTcpServer *server;

    QHostAddress getHostAddress();
    void setHostAddress();
    quint16 getHostPort();
    void setHostPort();

    void attemptConnection();
    void connectionAccepted();
    void readSocket(QTcpSocket *socket);

private:
    QHostAddress m_hostAddress;
    quint16 m_hostPort;

};

#endif // SERVER_H
