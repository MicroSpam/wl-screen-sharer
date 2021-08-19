#ifndef HOSTCLIENT_H
#define HOSTCLIENT_H

#include "Common.h"
#include "ErrorHandler.h"

class HostClient {
public:
    HostClient(int w, int h);
    ~HostClient();
    
    void UpdateClientWindow();
    
    std::unique_ptr<SDL_Event> event;    
private:
    SDL_Window* m_window;    

};

#endif