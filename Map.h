//
// Created by fredr on 02.04.2020.
//

#ifndef PACMAN_MAP_H
#define PACMAN_MAP_H


#include <SDL_render.h>
#include <vector>
#include "Rails.h"
#include "Screen.h"
#include "SDL_utility.h"
#include "Pill.h"


class Map {

public:
    static Map *getInstance();
    static void deleteInstance();
    void renderMap();
    std::vector<Rails> getRails();
    void initPills();
    std::vector<Pill*> getPills();

private:
    Map();
    ~Map();
    static Map *instance;
    SDL_Texture *txMap;
    std::vector<Rails> arrayOfRails;
    std::vector<Rails> castleRails;
    std::vector<Pill*> pills;


};


#endif //PACMAN_MAP_H
