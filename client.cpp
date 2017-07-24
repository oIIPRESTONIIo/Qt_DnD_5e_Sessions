#include "client.h"

Client::Client(QString hostIP, quint16 hostPort) : m_hostAddress(hostIP), m_hostPort(hostPort)
{
    tcpSocket = new QTcpSocket();
}

Client::~Client()
{
    qDebug() << "Client destroyed!";
}

void Client::connect()
{
    tcpSocket->connectToHost(m_hostAddress, m_hostPort, QIODevice::ReadWrite);

    if(tcpSocket->waitForConnected())
    {

    } else {
        qDebug() << "Couldn't Connect";
    }
}
