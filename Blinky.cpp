//
// Created by fredr on 04.04.2020.
//

#include "Blinky.h"


Blinky *Blinky::instance = nullptr;

Blinky::Blinky() : GameObject("../data/gfx/blinky_1.png", {280, 222})
{

}

Blinky::~Blinky()
{
    deleteInstance();
}

Blinky *Blinky::getInstance()
{
    if (!instance)
        instance = new Blinky;
    return instance;
}

void Blinky::deleteInstance()
{
    if (instance)
        delete instance;
    instance = nullptr;
}



