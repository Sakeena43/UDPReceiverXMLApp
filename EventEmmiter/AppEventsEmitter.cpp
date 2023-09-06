#include "AppEventsEmitter.h"

AppEventsEmitter* AppEventsEmitter::appEventEmitterInstance = nullptr;

AppEventsEmitter::AppEventsEmitter()
{
    // Private Constructor
}

AppEventsEmitter *AppEventsEmitter::getEventEmitter()
{
    if(appEventEmitterInstance == nullptr)
       {
           appEventEmitterInstance = new AppEventsEmitter();
       }
    return appEventEmitterInstance;
}

AppEventsEmitter::~AppEventsEmitter()
{
    delete appEventEmitterInstance;
}
