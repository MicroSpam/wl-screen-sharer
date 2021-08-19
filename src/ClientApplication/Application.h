#ifndef APPLICATION_H
#define APPLICATION_H

#include "Common.h"
//#include "ErrorHandler.h"
#include "ENetClientObject.h"

class Application {
public:
    Application();
    ~Application();
    
    void EventLoop();
    void CheckQuit();
        
    bool quit = false;    
private:
    std::unique_ptr<ENetClientObject> m_clientObject;
};

#endif