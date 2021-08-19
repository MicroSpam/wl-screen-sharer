#ifndef ENET_CLIENT_OBJECT_H
#define ENET_CLIENT_OBJECT_H

#include "Common.h"
#include "ErrorHandler.h"
#define DEFAULT_PORT 53641

class ENetClientObject {
public:
    ENetClientObject();
    ~ENetClientObject();

    void ProcessEvents();

private:
    ENetAddress m_address;
    ENetEvent m_event;
    ENetHost* m_client;
    ENetPeer* m_peer;
};

#endif