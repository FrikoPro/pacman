//
// Created by fredr on 08.04.2020.
//

#ifndef PACMAN_NPC_H
#define PACMAN_NPC_H

#include "GameObject.h"
#include "Pacman.h"
#include <set>
#include <algorithm>

class Npc : public GameObject {

public:
    Npc(const char *path, SDL_Point pos);
    ~Npc();

    void moveLeft();
    void moveRight();
    void moveDown();
    void moveUp();

    virtual void move();

    std::vector<SDL_Point> findPath(SDL_Point start, SDL_Point dest);
    void
    calculatePath(std::vector<SDL_Point> &stack, std::set<SDL_Point *> &alreadyVisted, SDL_Point current, Rails rail);
    std::vector<SDL_Point> getAdjacents(SDL_Point point);
    bool isPointIn(std::set<SDL_Point*> alreadyVisted, SDL_Point point);
    bool isPathTo(std::vector<SDL_Point> &stack, Rails rail);
    bool isValidPoint(SDL_Point point);

protected:

    SDL_Point destination;
    SDL_Point goal;
    std::vector<SDL_Point> path;

};


#endif //PACMAN_NPC_H
