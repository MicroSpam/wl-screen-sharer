#ifndef APPLICATION_H
#define APPLICATION_H

#include "Common.h"
#include "HostClient.h"
#include "ENetHostObject.h"
#include "ErrorHandler.h"

class Application {
public:
    Application();
    ~Application();
    
    void EventLoop();
    
    bool quit = false;    
private:
    std::unique_ptr<HostClient> 	m_hostClient;
    std::unique_ptr<ENetHostObject> 	m_enetHostObject;    
};

#endif