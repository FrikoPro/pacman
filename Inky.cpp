//
// Created by fredr on 14.04.2020.
//

#include "Inky.h"

Inky *Inky::instance = nullptr;

Inky::Inky() : Npc("../data/gfx/inky_1.png", SDL_Point{310, 222}){}

Inky::~Inky()
{
    deleteInstance();
}

Inky *Inky::getInstance()
{
    if(!instance) {
        instance = new Inky;
    }
    return instance;
}

void Inky::deleteInstance()
{
    if(instance){
        delete instance;
    }
    instance = nullptr;
}

void Inky::move()
{
    int randNum = rand() % 92;
    destination = arrayOfRails[randNum].start;
    Npc::move();
}