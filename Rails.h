//
// Created by fredr on 02.04.2020.
//

#ifndef PACMAN_RAILS_H
#define PACMAN_RAILS_H


#include <SDL_rect.h>
#include <vector>
#include "SDL_utility.h"
#include "Pill.h"


class Rails {

public:
    Rails(SDL_Point start, SDL_Point end);
    Rails();
    ~Rails();

    bool operator==(const Rails &obj1);
    bool operator==(const SDL_Point &point);

    SDL_Point start;
    SDL_Point end;

    std::vector<Pill*> pills;



};



#endif //PACMAN_RAILS_H