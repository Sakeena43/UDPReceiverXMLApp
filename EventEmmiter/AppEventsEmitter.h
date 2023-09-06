#ifndef APPEVENTSEMITTER_H
#define APPEVENTSEMITTER_H

#include <QObject>
#include "../StoreAppStruct.h"
/*
* This class is responsible to handle App related events
*/

//#include "TrackInformation/TrackInformationTypeSupportImpl.h"

class AppEventsEmitter  : public QObject
{
    Q_OBJECT

private : //members
    AppEventsEmitter();
    static AppEventsEmitter *appEventEmitterInstance;

public: //functions
    static AppEventsEmitter *getEventEmitter();
    ~AppEventsEmitter();

signals:

    void notifyStruct(ShopStruct structShop);

};

#endif // APPEVENTSEMITTER_H
