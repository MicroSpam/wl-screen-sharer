#include "Application.h"

SDL_Window* m_window;

int main(int argc, char** argv) {
    
    Application app;
    app.EventLoop();    
        
    return 0;
}