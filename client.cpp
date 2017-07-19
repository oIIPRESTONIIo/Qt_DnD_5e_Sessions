#include "client.h"

Client::Client(QHostAddress hostIP, quint16 hostPort) : m_hostAddress(hostIP), m_hostPort(hostPort)
{
    QTcpSocket *tcpSocket = new QTcpSocket();
}

void Client::connect()
{
    tcpSocket->connectToHost(m_hostAddress, m_hostPort, QIODevice::ReadWrite);
}
