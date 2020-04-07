//
// Created by fredr on 04.04.2020.
//

#ifndef PACMAN_BLINKY_H
#define PACMAN_BLINKY_H

#include "GameObject.h"



class Blinky : public GameObject {

public:
    static Blinky *getInstance();
    static void deleteInstance();

private:
    Blinky();
    ~Blinky();

    static Blinky *instance;


};


#endif //PACMAN_BLINKY_H
