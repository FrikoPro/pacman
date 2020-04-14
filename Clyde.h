//
// Created by fredr on 14.04.2020.
//

#ifndef PACMAN_CLYDE_H
#define PACMAN_CLYDE_H

#include "Npc.h"

class Clyde : public Npc {

public:
    static Clyde *getInstance();
    static void *deleteInstance();

    void move();

private:
    Clyde();
    ~Clyde();

    static Clyde *instance;

};


#endif //PACMAN_CLYDE_H
