//
// Created by fredr on 01.04.2020.
//

#ifndef PACMAN_GAMEOBJECT_H
#define PACMAN_GAMEOBJECT_H

#include <SDL2/SDL.h>
#include <vector>
#include "Screen.h"


class Rails;
class Pill;

class GameObject {

public:
    GameObject(const char *path, SDL_Point pos);

    virtual ~GameObject();

    virtual void update();

    void render();

    virtual void move();

    bool isStillAlive();

    void setStillAlive(bool stillAlive);

protected:
    SDL_Point pos;
    SDL_Texture *objTexture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer *renderer;
    SDL_Point teleportRight = SDL_Point{515, 215};
    SDL_Point teleportLeft = SDL_Point{100, 215};
    std::vector<Rails> arrayOfRails;

    bool stillAlive = true;
};


#endif //PACMAN_GAMEOBJECT_H
