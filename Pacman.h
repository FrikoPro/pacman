//
// Created by fredr on 02.04.2020.
//

#ifndef PACMAN_PACMAN_H
#define PACMAN_PACMAN_H

#include "GameObject.h"

class Pacman : public GameObject {

public:

    static Pacman *getInstance();
    static void deleteInstance();


private:

    static Pacman *instance;
    Pacman();
    ~Pacman();


};


#endif //PACMAN_PACMAN_H
