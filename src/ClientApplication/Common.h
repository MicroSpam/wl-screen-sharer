#ifndef COMMON_H
#define COMMON_H

#include <SDL2/SDL.h>
#include <enet/enet.h>
#include <stdio.h>
#include <string>
#include <memory>
#include <vector>
#include <mutex>
#include <iostream>

#include "ErrorHandler.h"



namespace Utilities {
    //thread safe
    template<typename... Ts>
    void printf_ts(const std::string& format, const Ts&... args) {
        std::mutex m;
        m.lock();
        printf(format.c_str(), args...);
        m.unlock();
    }

}

#endif