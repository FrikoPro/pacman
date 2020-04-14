//
// Created by fredr on 02.04.2020.
//

#include "Pacman.h"

Pacman *Pacman::instance = nullptr;

Pacman *Pacman::getInstance()
{
    if (!instance) {
        instance = new Pacman();
    }
    return instance;
}

void Pacman::deleteInstance()
{
    if (instance) {
        delete instance;
    }
    instance = nullptr;
}

Pacman::Pacman() : pre_direction(STOP), direction(LEFT),
                   GameObject("../data/gfx/pacman.png", {330, 339})
{

}

Pacman::~Pacman()
{
    deleteInstance();
}

void Pacman::move()
{
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

bool Pacman::checkRail(Direction direction)
{


    switch (direction) {
        case DOWN:
            for (Rails rail : arrayOfRails) {
                if (pos.y >= rail.start.y && pos.y < rail.end.y) {
                    if (pos.x == rail.start.x) {
                        currentRail = &rail;
                        return true;
                    }
                }
            }
            break;
        case UP:
            for (Rails rail : arrayOfRails) {
                if (pos.y > rail.start.y && pos.y <= rail.end.y) {
                    if (pos.x == rail.start.x) {
                        currentRail = &rail;
                        return true;
                    }
                }
            }
            break;
        case LEFT:
            for (Rails rail : arrayOfRails) {
                if (pos.x > rail.start.x && pos.x <= rail.end.x) {
                    if (pos.y == rail.start.y) {
                        currentRail = &rail;
                        return true;
                    }
                }
            }
            break;
        case RIGHT:
            for (Rails rail : arrayOfRails) {
                if (pos.x >= rail.start.x && pos.x < rail.end.x) {
                    if (pos.y == rail.start.y) {
                        currentRail = &rail;
                        return true;
                    }
                }
            }
            break;
        case STOP:
            for (Rails rail : arrayOfRails) {
                if(pos.x == rail.start.x && pos.y == rail.start.y ||(
                        pos.x == rail.end.x && pos.y == rail.end.y)) {
                    currentRail = &rail;
                    break;
                }
            }
    }
    return false;

}

SDL_Point Pacman::getPosition()
{
    return pos;
}

SDL_Rect Pacman::getRect()
{
    return destRect;
}

void Pacman::moveUp()
{

    if (pos.y - 2 <= currentRail->start.y) {
        pos.y = currentRail->start.y;
    } else {
        pos.y -= 2;
    }

}

void Pacman::moveDown()
{

    if (pos.y + 2 >= currentRail->end.y) {
        pos.y = currentRail->end.y;
    } else {
        pos.y += 2;
    }

}

void Pacman::moveRight()
{


    if (pos.x + 2 >= currentRail->end.x) {
        pos.x = currentRail->end.x;
    } else {
        pos.x += 2;
    }

}

void Pacman::moveLeft()
{

    if (pos.x - 2 <= currentRail->start.x) {
        pos.x = currentRail->start.x;
    } else {
        pos.x -= 2;
    }

}

void Pacman::setDirection(Direction direction)
{
    this->direction = direction;
}

void Pacman::setPreDirection(Direction direction)
{
    this->pre_direction = direction;
}

Pacman::Direction Pacman::getDirection()
{
    return direction;
}

Pacman::Direction Pacman::getPreDirection()
{
    return pre_direction;
}



