//
// Created by fredr on 01.04.2020.
//

#include "GameObject.h"
#include "Map.h"

GameObject::GameObject(const char *path, SDL_Point pos) : objTexture(Screen::loadImage(path, 255)),
                                                          renderer(Screen::renderer), pos(pos),
                                                          arrayOfRails(Map::getInstance()->getRails())
{
}

GameObject::~GameObject()
{}

void GameObject::update()
{

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

    if (&pos == teleportLeft) {
        pos.x = 515;
    } else if (&pos == teleportRight) {
        pos.x = 100;
    }

}

void GameObject::render()
{

    SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}


void GameObject::moveUp()
{
    if (pos.y - 2 < goal.y) {
        pos.y = goal.y;
    } else
        pos.y -= 2;
}

void GameObject::moveDown()
{
    if (pos.y + 2 > goal.y)
        pos.y = goal.y;
    else
        pos.y += 2;
}

void GameObject::moveRight()
{
    if (pos.x + 2 > goal.x)
        pos.x = goal.x;
    else
        pos.x += 2;
}

void GameObject::moveLeft()
{
    if (pos.x - 2 < goal.x)
        pos.x = goal.x;
    else
        pos.x -= 2;
}



