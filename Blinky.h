//
// Created by fredr on 04.04.2020.
//

#ifndef PACMAN_BLINKY_H
#define PACMAN_BLINKY_H

#include "GameObject.h"
#include "Pacman.h"
#include "Rails.h"
#include <set>
#include <algorithm>
#include "SDL_utility.h"


class Blinky : public GameObject {

public:
    static Blinky *getInstance();
    static void deleteInstance();

    void move();
    std::vector<SDL_Point> findPath(SDL_Point start, SDL_Point dest, Rails *rail);
    void calculatePath(std::vector<SDL_Point> &stack, std::set<SDL_Point *> &alreadyVisted, SDL_Point current,
                       Rails rail);
    std::vector<SDL_Point> getAdjacents(SDL_Point point);
    bool isPointIn(std::set<SDL_Point*> alreadyVisted, SDL_Point point);
    bool isPathTo(std::vector<SDL_Point> &stack, Rails rail);
    bool isValidPoint(SDL_Point point);
private:
    Blinky();
    ~Blinky();

    static Blinky *instance;
    std::vector<SDL_Point> path;


};


#endif //PACMAN_BLINKY_H
