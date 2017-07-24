#include "server.h"

Server::Server(QHostAddress hostIP, quint16 hostPort) :
    m_hostAddress(hostIP), m_hostPort(hostPort)
{
    QTcpServer *server = new QTcpServer;
}

void Server::attemptConnection()
{
    connect(server, SIGNAL(newConnection()), this, SLOT(connectionAccepted()));

    server->listen(m_hostAddress, m_hostPort);
}

void Server::connectionAccepted()
{

    QTcpSocket *socket = server->nextPendingConnection();

    connect(socket, SIGNAL(readyRead()), this, SLOT(readSocket(socket)));
}

void Server::readSocket(QTcpSocket *socket)
{

    qDebug() << socket->readBufferSize();

    QByteArray data = socket->readAll();
}


Server::Server(QObject *parent) :
    QObject(parent)
{
    server = new QTcpServer(this);

    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));

    if(!server->listen(QHostAddress::Any, 1234))
    {
        qDebug() << "Server could not start!";
    }
    else
    {
        qDebug() << "Server started!";
    }
}

Server::~Server()
{
    qDebug() << "Server destroyed!";
}

void Server::newConnection()
{
    QTcpSocket *socket = server->nextPendingConnection();

    socket->write("hello client\r\n");
    socket->flush();

    socket->waitForBytesWritten(3000);

    socket->close();
}
