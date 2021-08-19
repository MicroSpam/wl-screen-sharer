#include "ENetHostObject.h"

ENetHostObject::ENetHostObject() {
    if(enet_initialize() != 0) {
        ErrorHandler::FatalError("ENet failed to initialize!",
                                ErrorHandler::ErrorType::ERROR_GENERIC);
    }
    printf("ENet initialized.\n");
    
    m_address.host = ENET_HOST_ANY;
    m_address.port = DEFAULT_PORT;
    
    m_server = enet_host_create(&m_address, 1, 1, 0, 0);
    
    if(m_server == nullptr) {
        ErrorHandler::FatalError("ENet server could not be created!",
                                ErrorHandler::ErrorType::ERROR_GENERIC);
    }
    
    printf("ENet server created.\n");
    printf("Address: %x:%d\n", m_address.host, m_address.port);
    
}

ENetHostObject::~ENetHostObject() {
    enet_host_destroy(m_server);
    enet_deinitialize();
    printf("Host destroyed.\n");
}

static void ENetHostObject::ProcessEvents(const ENetHostObject& object) {
    while(enet_host_service(object.m_server, &(object.m_event), 100) > 0) {
        switch(object.m_event.type) {
        case ENET_EVENT_TYPE_CONNECT:
            Utilities::printf_ts("New client connected from %x, %u\n",
                                object.m_event.peer->address.host,
                                object.m_event.peer->address.port);
            break;
        case ENET_EVENT_TYPE_RECEIVE:
            Utilities::printf_ts("Packet received. size: %lu\n", object.m_event.packet->dataLength);
            break;
        case ENET_EVENT_TYPE_DISCONNECT:
            Utilities::printf_ts("%x:%u disconnected.\n", 
                                object.m_event.peer->address.host,
                                object.m_event.peer->address.port);
            break;
        default:
        
        break;
        }
    }

}