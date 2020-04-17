//
// Created by fredr on 06.04.2020.
//

#ifndef PACMAN_SDL_UTILITY_H
#define PACMAN_SDL_UTILITY_H


#include <SDL_rect.h>

inline bool operator==(SDL_Point const *obj1, SDL_Point const &obj2)
{
    return obj1->x == obj2.x && obj1->y == obj2.y;
}

#endif //PACMAN_SDL_UTILITY_H
