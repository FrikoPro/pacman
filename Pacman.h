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
    void setPosition(SDL_Point point);
    SDL_Rect getRect();

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

    void decrementHp();

    int getHp();

private:

    static Pacman *instance;
    Direction pre_direction;
    Rails *currentRail;
    Direction direction;
    int hp = 3;

    Pacman();
    ~Pacman();


};


#endif //PACMAN_PACMAN_H
