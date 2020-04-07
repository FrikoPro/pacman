//
// Created by fredr on 01.04.2020.
//

#ifndef PACMAN_GAMEOBJECT_H
#define PACMAN_GAMEOBJECT_H

#include <SDL2/SDL.h>
#include <vector>
#include "Screen.h"

class Rails;

class GameObject {

public:
    GameObject(const char *path, SDL_Point pos);

    virtual ~GameObject();

    void update();

    void render();

    enum Direction {LEFT, RIGHT, UP, DOWN, STOP};

    void moveLeft();
    void moveRight();
    void moveDown();
    void moveUp();

    virtual void move();

protected:
    SDL_Point pos;
    SDL_Point goal;
    SDL_Texture *objTexture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer *renderer;
    std::vector<Rails> arrayOfRails;
    SDL_Point teleportRight = SDL_Point{515, 215};
    SDL_Point teleportLeft = SDL_Point{100, 215};
    Direction direction;
};


#endif //PACMAN_GAMEOBJECT_H
