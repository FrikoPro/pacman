//
// Created by fredr on 14.04.2020.
//

#ifndef PACMAN_PINKY_H
#define PACMAN_PINKY_H


#include "Npc.h"

class Pinky : public Npc {

public:
    static Pinky *getInstance();

    static void deleteInstance();

    void move() override;

private:
    Pinky();

    ~Pinky() override;

    static Pinky *instance;
};


#endif //PACMAN_PINKY_H
