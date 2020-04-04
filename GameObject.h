//
// Created by fredr on 01.04.2020.
//

#ifndef PACMAN_GAMEOBJECT_H
#define PACMAN_GAMEOBJECT_H

#include <SDL2/SDL.h>
#include <vector>
#include "Map.h"

class GameObject {

public:
    GameObject(const char *path, int x, int y);

    virtual ~GameObject();

    void update();

    void render();

    enum Direction {LEFT, RIGHT, UP, DOWN, STOP};

    void setDirection(Direction direction);
    void setPreDirection(Direction direction);

    Direction getDirection();
    Direction getPreDirection();

    bool checkRail(Direction direction);

    void moveLeft();
    void moveRight();
    void moveDown();
    void moveUp();

protected:
    int xpos;
    int ypos;
    Direction direction;
    Direction pre_direction;
    Rails *currentRail;
    SDL_Texture *objTexture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer *renderer;
    std::vector<Rails> arrayOfRails;

};


#endif //PACMAN_GAMEOBJECT_H
