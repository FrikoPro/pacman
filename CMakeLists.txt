cmake_minimum_required(VERSION 3.15)
project(pacman)
INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2_IMAGE REQUIRED SDL2_image>=2.0.0)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
set(CMAKE_CXX_STANDARD 17)

add_executable(pacman main.cpp Screen.cpp Screen.h GameManager.cpp GameManager.h GameObject.cpp GameObject.h Pacman.cpp Pacman.h Rails.cpp Rails.h Map.cpp Map.h Blinky.cpp Blinky.h SDL_utility.h Pill.cpp Pill.h Npc.cpp Npc.h Clyde.cpp Clyde.h Inky.cpp Inky.h Pinky.cpp Pinky.h)
target_link_libraries(pacman ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})