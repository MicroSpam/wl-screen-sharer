cmake_minimum_required(VERSION 3.10)

set(HOST_SRC_DIR "./src/HostApplication")
set(CLIENT_SRC_DIR "./src/ClientApplication")

project(ScreenSharerHost)
project(ScreenSharerClient)

add_compile_options(-ggdb)

add_executable(ScreenSharerHost ${HOST_SRC_DIR}/main.cpp
${HOST_SRC_DIR}/HostClient.cpp
${HOST_SRC_DIR}/Application.cpp 
${HOST_SRC_DIR}/ENetHostObject.cpp)

add_executable(ScreenSharerClient ${CLIENT_SRC_DIR}/main.cpp
${CLIENT_SRC_DIR}/Application.cpp)

set_target_properties(ScreenSharerHost PROPERTIES CXX_STANDARD 17)
set_target_properties(ScreenSharerClient PROPERTIES CXX_STANDARD 17)

target_link_libraries(ScreenSharerHost PRIVATE SDL2main SDL2 enet)
target_link_libraries(ScreenSharerClient PRIVATE enet)