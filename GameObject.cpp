//
// Created by fredr on 01.04.2020.
//

#include "GameObject.h"
#include "Map.h"


GameObject::GameObject(const char *path, SDL_Point pos) : objTexture(Screen::loadImage(path, 255)),
                                                          arrayOfRails(Map::getInstance()->getRails()),
                                                          renderer(Screen::renderer), pos(pos)
                                                          {}

GameObject::~GameObject()
{}

void GameObject::update()
{

    if (&pos == teleportLeft) {
        pos.x = 515;
    } else if (&pos == teleportRight) {
        pos.x = 100;
    }

    srcRect.h = 23;
    srcRect.w = 23;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = pos.x;
    destRect.y = pos.y;
    destRect.w = srcRect.w;
    destRect.h = srcRect.h;

}

void GameObject::move()
{
}

void GameObject::render()
{

    SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}






