//
// Created by fredr on 06.04.2020.
//

#include "Pill.h"

Pill::Pill(SDL_Point pos) : GameObject("../data/gfx/pille.png", pos) {
    objTexture = Screen::loadImage("../data/gfx/pille.png", -1);

    srcRect.h = 3;
    srcRect.w = 3;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = pos.x;
    destRect.y = pos.y;
    destRect.w = srcRect.w;
    destRect.h = srcRect.h;
}

Pill::~Pill()
{}
