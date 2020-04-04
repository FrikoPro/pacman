//
// Created by fredr on 04.04.2020.
//
#include "Blinky.h"

Blinky *Blinky:: instance = nullptr;
Blinky::Blinky() : GameObject("../data/gfx/blinky_1.png", 280, 222)
{
}

Blinky::~Blinky()
{
    deleteInstance();
}

Blinky * Blinky::getInstance()
{
    if(!instance)
        instance = new Blinky;
    return instance;
}

void Blinky::deleteInstance()
{
    if(instance)
        delete instance;
    instance = nullptr;
}

void Blinky::move()
{
    GameObject::move();
    findPath();

}

void Blinky::findPath()
{



    std::vector<Rails*> stack;
    std::vector<Direction*> vectorDir;
    std::vector<Rails*> visited;

    Direction arr[4] = {LEFT, DOWN, RIGHT, UP};

    vectorDir.emplace_back(arr);

    stack.emplace_back(currentRail);
    calculatePath(stack, visited);

}

void Blinky::calculatePath(std::vector<Rails*> &stack, std::vector<Rails*> &visited)
{

    if(foundRail(stack.back())) {
        return;
    } else {

    }
}

bool Blinky::foundRail(Rails *rail)
{
    SDL_Point pacmanPos = Pacman::getInstance()->getPosition();
    if(pacmanPos.x == rail->x1 && pacmanPos.y == rail->y1) {
        return true;
    } else if(pacmanPos.x == rail->x2 && pacmanPos.y == rail->y2) {
        return true;
    }
    return false;
}
