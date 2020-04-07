//
// Created by fredr on 01.04.2020.
//

#ifndef PACMAN_GAMEOBJECT_H
#define PACMAN_GAMEOBJECT_H

#include <SDL2/SDL.h>
#include <vector>
#include <set>
#include <algorithm>
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

    std::vector<SDL_Point> findPath(SDL_Point start, SDL_Point dest, Rails *rail);
    void calculatePath(std::vector<SDL_Point> &stack, std::set<SDL_Point *> &alreadyVisted, SDL_Point current,
                       Rails rail);
    std::vector<SDL_Point> getAdjacents(SDL_Point point);
    bool isPointIn(std::set<SDL_Point*> alreadyVisted, SDL_Point point);
    bool isPathTo(std::vector<SDL_Point> &stack, Rails rail);
    bool isValidPoint(SDL_Point point);

protected:
    SDL_Point pos;
    SDL_Point goal;
    SDL_Texture *objTexture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer *renderer;
    std::vector<Rails> arrayOfRails;
    SDL_Point teleportRight = SDL_Point{515, 215};
    SDL_Point teleportLeft = SDL_Point{100, 215};
    std::vector<SDL_Point> path;
};


#endif //PACMAN_GAMEOBJECT_H
