#ifndef UDPRECEIVER_H
#define UDPRECEIVER_H

#include <QObject>
#include <QUdpSocket>
#include <bitset>
#include "QTimer"
#include "../EventEmmiter/AppEventsEmitter.h"
class UDPReceiver: public QObject
{
    Q_OBJECT
public:
    UDPReceiver();
    void ReceivedUDPDataPacket(QString ip,int port);
    QUdpSocket  *socketServer;
      ShopStruct structShop;
public slots:
    void readUDPPacket();
    void parseData(QByteArray data);
};

#endif // UDPRECEIVER_H
