//
// Created by fredr on 02.04.2020.
//

#ifndef PACMAN_MAP_H
#define PACMAN_MAP_H


#include <SDL_render.h>
#include <vector>
#include "Rails.h"
#include "Screen.h"

class Map {

public:
    static Map *getInstance();
    static void deleteInstance();
    void renderMap();
    std::vector<Rails> getRails();

private:
    Map();
    ~Map();
    static Map *instance;
    SDL_Texture *txMap;
    std::vector<Rails> arrayOfRails;


};


#endif //PACMAN_MAP_H
