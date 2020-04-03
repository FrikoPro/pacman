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

Pacman::Pacman() : GameObject("../data/gfx/pacman.png",330, 339){}

Pacman::~Pacman()
{}



