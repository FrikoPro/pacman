//
// Created by fredr on 02.04.2020.
//

#include "Pacman.h"

Pacman *Pacman::instance = nullptr;
Pacman *Pacman::getInstance()
{
    if(!instance) {
        instance = new Pacman();
    }
    return instance;
}

void Pacman::deleteInstance()
{
    if(instance) {
        delete instance;
    }
    instance = nullptr;
}

Pacman::Pacman() : GameObject("../data/gfx/pacman.png",330, 339) {}

Pacman::~Pacman()
{
    deleteInstance();
}

void Pacman::move()
{
    GameObject::move();

    if (checkRail(direction)) {

        switch (direction) {
            case LEFT:
                moveLeft();
                break;
            case RIGHT:
                moveRight();
                break;
            case UP:
                moveUp();
                break;
            case DOWN:
                moveDown();
                break;
            default:
                break;
        }
        pre_direction = STOP;

    } else if (checkRail(pre_direction)) {

        switch (pre_direction) {
            case LEFT:
                moveLeft();
                break;
            case RIGHT:
                moveRight();
                break;
            case UP:
                moveUp();
                break;
            case DOWN:
                moveDown();
                break;
            default:
                break;
        }
    }
}

SDL_Point Pacman::getPosition()
{
    return position;
}



