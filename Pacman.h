//
// Created by fredr on 02.04.2020.
//

#ifndef PACMAN_PACMAN_H
#define PACMAN_PACMAN_H

#include "GameObject.h"
#include "Rails.h"
#include "Map.h"

class Pacman : public GameObject {

public:

    static Pacman *getInstance();
    static void deleteInstance();
    void move();
    SDL_Point getPosition();
    Rails *getCurrentRail();

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



private:

    static Pacman *instance;
    Direction pre_direction;
    Rails *currentRail;
    Direction direction;

    Pacman();
    ~Pacman();


};


#endif //PACMAN_PACMAN_H
