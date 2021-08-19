#include "ENetClientObject.h"

ENetClientObject::ENetClientObject() {
    if(enet_initialize() != 0) {
        ErrorHandler::FatalError("ENet failed to initialize!",
                                ErrorHandler::ErrorType::ERROR_GENERIC);
    }
    printf("ENet initialized.\n");
    
    m_address.port = DEFAULT_PORT;
    enet_address_set_host(&m_address, "127.0.0.1");

    m_client = enet_host_create(nullptr, 0, 2, 0, 0);
    
    m_peer = enet_host_connect(m_client, &m_address, 1, 0);
    
    if(m_peer == nullptr) {
        ErrorHandler::FatalError("ENet client could not find any suitable connections.",
                                ErrorHandler::ErrorType::ERROR_GENERIC);
    }
    
    if(m_client == nullptr) {
        ErrorHandler::FatalError("ENet client could not be created!",
                                ErrorHandler::ErrorType::ERROR_GENERIC);
    }
    
    printf("ENet client created.\n");
    printf("Address: %x:%d\n", m_address.host, m_address.port);
}

ENetClientObject::~ENetClientObject() {
    enet_host_destroy(m_client);
    enet_deinitialize();
    printf("Client destroyed.\n");
}

void ENetClientObject::ProcessEvents() {
    while(enet_host_service(m_client, &m_event, 100) > 0) {
        switch(m_event.type) {
            case ENET_EVENT_TYPE_RECEIVE : 
                printf("A packet from %x:%u was received, containing %lu bytes.\n",
                        m_event.peer->address.host,
                        m_event.peer->address.port,
                        m_event.packet->dataLength);
                    enet_packet_destroy(m_event.packet);
                break;
            case ENET_EVENT_TYPE_DISCONNECT :
                printf("Client has disconnected.\n");
                break;
        }
    }
}