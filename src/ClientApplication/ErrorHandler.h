#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#include "Common.h"


namespace ErrorHandler {
    enum ErrorType {ERROR_SDL, ERROR_GENERIC};

    static void FatalError(const std::string& what, ErrorType type) {
        std::string errorString = what;
        std::string extra;
        
        //Show additional info depending on which resource crashed
        switch(type) {
            case ERROR_SDL: 
                extra = std::string(SDL_GetError()); 
            break;
            default: break; 
        }
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Fatal Error!",
                                (errorString+extra).c_str(), NULL);
        exit(EXIT_FAILURE);
    }
}

#endif