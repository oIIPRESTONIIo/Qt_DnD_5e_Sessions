#include "server.h"

Server::Server(QHostAddress hostIP, quint16 hostPort) :
    m_hostAddress(hostIP), m_hostPort(hostPort)
{
    QTcpServer *server = new QTcpServer;//(this);
}

void Server::attemptConnection()
{
    connect(server, SIGNAL(newConnection()), this, SLOT(connectionAccepted()));

    server->listen(m_hostAddress, m_hostPort);
}

void Server::connectionAccepted()
{
    QTcpSocket socket = new QTcpSocket(server->nextPendingConnection());

    char *recvbuf = new char[socket->readBufferSize()];
    qDebug() << socket.readBufferSize();
}
