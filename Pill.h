//
// Created by fredr on 06.04.2020.
//

#ifndef PACMAN_PILL_H
#define PACMAN_PILL_H

#include "GameObject.h"

class Pill : public GameObject {

public:
    explicit Pill(SDL_Point pos);

    ~Pill() override;

    void update() override;

};


#endif //PACMAN_PILL_H
