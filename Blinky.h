//
// Created by fredr on 04.04.2020.
//

#ifndef PACMAN_BLINKY_H
#define PACMAN_BLINKY_H

#include "GameObject.h"
#include "Pacman.h"


class Blinky : public GameObject {

public:
    static Blinky *getInstance();
    static void deleteInstance();

    void move();
    void findPath();
    void calculatePath(std::vector<Rails*> &stack, std::vector<Rails*> &visited);
    bool foundRail(Rails *rail);

private:
    Blinky();
    ~Blinky();

    static Blinky *instance;
    SDL_Point position {xpos, ypos};

};


#endif //PACMAN_BLINKY_H
