#include "Application.h"

Application::Application() {
    m_hostClient = std::make_unique<HostClient>(800, 600);
    m_enetHostObject = std::make_unique<ENetHostObject>();
    m_hostThread = std::make_unique<std::thread>(m_enetHostObject->ProcessEvents);
    printf("Application Initialized.\n");
}

Application::~Application() {
    printf("Application Closing...\n");
    m_hostThread->join();
}

void Application::EventLoop() {
    while(!quit) {
        while(SDL_PollEvent(m_hostClient->event.get())) {
            switch(m_hostClient->event->type) {
                case SDL_QUIT: quit = true;
                
                break;
                default: break;
            }
            m_enetHostObject->ProcessEvents();
            m_hostClient->UpdateClientWindow();
        }
    }
}