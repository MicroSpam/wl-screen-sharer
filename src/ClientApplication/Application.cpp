#include "Application.h"

Application::Application() {
    m_clientObject = std::make_unique<ENetClientObject>();
    printf("Application Initialized.\n");
}

Application::~Application() {
    printf("Application Closing...\n");
}

void Application::EventLoop() {
    while(!quit) {
        m_clientObject->ProcessEvents();    
    
        CheckQuit();                    
    }
}

void Application::CheckQuit() {
    std::string in;
    std::cin >> in;
    if(in == "quit" || in == "q") {
        quit = true;    
    }
}