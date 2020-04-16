//
// Created by fredr on 04.04.2020.
//

#ifndef PACMAN_BLINKY_H
#define PACMAN_BLINKY_H

#include "Npc.h"
#include "Pacman.h"



class Blinky : public Npc {

public:
    static Blinky *getInstance();
    static void deleteInstance();

    void move();

private:
    Blinky();
    ~Blinky();

    static Blinky *instance;



};


#endif //PACMAN_BLINKY_H
