//
// Created by fredr on 14.04.2020.
//

#ifndef PACMAN_INKY_H
#define PACMAN_INKY_H


#include "Npc.h"

class Inky : public Npc {

public:
    static Inky *getInstance();

    static void deleteInstance();

    void move() override;

private:
    Inky();

    ~Inky() override;

    static Inky *instance;
};


#endif //PACMAN_INKY_H
