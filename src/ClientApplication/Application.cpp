#include "Application.h"

Application::Application() {
    printf("Application Initialized.\n");
}

Application::~Application() {
    printf("Application Closing...\n");
}

void Application::EventLoop() {
    while(!quit) {
    
    
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