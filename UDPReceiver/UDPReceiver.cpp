#include "UDPReceiver.h"

UDPReceiver::UDPReceiver()
{

    socketServer = new QUdpSocket();

    ReceivedUDPDataPacket("",4063);

}

void UDPReceiver::ReceivedUDPDataPacket(QString ip, int port)
{
    try {

        bool isBind = socketServer->bind(QHostAddress(ip), port);
        qInfo() << "Bind with  --->" << isBind;
        connect(socketServer,&QUdpSocket::readyRead,this,&UDPReceiver::readUDPPacket);

    } catch (...) {
        qWarning() << "ReceivedUDPDataPacket() : Failed";
    }
}

void UDPReceiver::readUDPPacket()
{
    while (socketServer->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(socketServer->pendingDatagramSize());

        QHostAddress senderAddress;
        quint16 senderPort;
        socketServer->readDatagram(datagram.data(), datagram.size(), &senderAddress, &senderPort);


        qInfo() << " Data " << datagram;
        parseData(datagram);
    }
}

void UDPReceiver::parseData(QByteArray data)
{
    QString recPacket = data.data();
    QStringList packtList = recPacket.split(",");



    if(packtList.size()>0){
        //check from previous
        if(packtList[1] == structShop.transactionDate)
        {

        }
        else{
            structShop.customerName = packtList[0];
            structShop.transactionDate = packtList[1];
            structShop.typeName = packtList[2];
            structShop.type = packtList[3];
            structShop.qty = packtList[4];
            qInfo() << " Data struct";

            emit AppEventsEmitter::getEventEmitter()->notifyStruct(structShop);
        }


    }
}

