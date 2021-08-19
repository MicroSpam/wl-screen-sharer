#ifndef ENET_CLIENT_OBJECT_H
#define ENET_CLIENT_OBJECT_H

#include "Common.h"
#define DEFAULT_PORT 53641

class ENetClientObject {
public:
    ENetClientObject();
    ~ENetClientObject();
private:
    ENetAddress m_address;
    ENetHost m_client;
    ENetPeer* m_peer;
};

#endif