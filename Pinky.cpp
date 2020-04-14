//
// Created by fredr on 14.04.2020.
//

#include "Pinky.h"

Pinky *Pinky::instance = nullptr;

Pinky::Pinky() : Npc("../data/gfx/pinky_1.png", SDL_Point{310, 222}) {}

Pinky::~Pinky()
{}

Pinky *Pinky::getInstance()
{
    if(!instance) {
        instance = new Pinky;
    }
    return instance;
}

void Pinky::deleteInstance()
{
    if(instance) {
        delete instance;
    }
    instance = nullptr;
}

void Pinky::move()
{
    int randNum = rand() % 92;
    destination = arrayOfRails[randNum].start;
    Npc::move();
}