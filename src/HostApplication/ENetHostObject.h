#ifndef ENET_HOST_OBJECT_H
#define ENET_HOST_OBJECT_H

#include "Common.h"
#include "ErrorHandler.h"

#define DEFAULT_PORT 53641

class ENetHostObject {
public:
    ENetHostObject();
    ~ENetHostObject();
    
    
private:
    ENetAddress m_address;
    ENetHost* m_server;
};

#endif