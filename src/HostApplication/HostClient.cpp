#include "HostClient.h"

HostClient::HostClient(int w, int h) {
    SDL_Init(SDL_INIT_EVERYTHING);
    m_window = SDL_CreateWindow("ClientWindow", SDL_WINDOWPOS_UNDEFINED,
                                                SDL_WINDOWPOS_UNDEFINED,
                                                w, h, SDL_WINDOW_SHOWN);
                                                
    if(m_window == nullptr) {
        ErrorHandler::FatalError("SDL Window failed to be created!", 
                                ErrorHandler::ErrorType::ERROR_SDL);
    }    
    event = std::make_unique<SDL_Event>();                                                    
}

HostClient::~HostClient() {
    if(m_window) {
        SDL_DestroyWindow(m_window);
    }
    SDL_Quit();
}

void HostClient::UpdateClientWindow() {
    SDL_UpdateWindowSurface(m_window);
}