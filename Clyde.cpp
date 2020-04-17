//
// Created by fredr on 14.04.2020.
//

#include "Clyde.h"

Clyde *Clyde::instance = nullptr;

Clyde::Clyde() : Npc("../data/gfx/clyde_1.png", SDL_Point{310, 222})
{}

Clyde::~Clyde()
= default;

Clyde *Clyde::getInstance()
{
    if (!instance) {
        instance = new Clyde;
    }
    return instance;
}

void Clyde::deleteInstance()
{
    if (instance) {
        delete instance;
        instance = nullptr;
    }

}

void Clyde::move()
{
    int randNum = rand() % 92;
    destination = arrayOfRails[randNum].start;
    Npc::move();
}