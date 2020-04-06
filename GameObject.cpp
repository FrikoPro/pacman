//
// Created by fredr on 01.04.2020.
//

#include "GameObject.h"
#include "Screen.h"

GameObject::GameObject(const char *path, SDL_Point pos) : objTexture(Screen::loadImage(path, 255)),
                                                          renderer(Screen::renderer), direction(LEFT),
                                                          pre_direction(STOP), pos(pos),
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

    if(pos.x == 100 && pos.y == 215) {
        pos.x = 515;
    } else if (pos.x == 515 && pos.y == 215) {
        pos.x = 100;
    }

}

void GameObject::render()
{

    SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}

bool GameObject::checkRail(Direction direction)
{


    switch (direction) {
        case DOWN:
            for (Rails rail : arrayOfRails) {
                if (pos.y >= rail.start.y && pos.y < rail.end.y) {
                    if (pos.x == rail.start.x) {
                        currentRail = rail;
                        return true;
                    }
                }
            }
            break;
        case UP:
            for (Rails rail : arrayOfRails) {
                if (pos.y > rail.start.y && pos.y <= rail.end.y) {
                    if (pos.x == rail.start.x) {
                        currentRail = rail;
                        return true;
                    }
                }
            }
            break;
        case LEFT:
            for (Rails rail : arrayOfRails) {
                if (pos.x > rail.start.x && pos.x <= rail.end.x) {
                    if (pos.y == rail.start.y) {
                        currentRail = rail;
                        return true;
                    }
                }
            }
            break;
        case RIGHT:
            for (Rails rail : arrayOfRails) {
                if (pos.x >= rail.start.x && pos.x < rail.end.x) {
                    if (pos.y == rail.start.y) {
                        currentRail = rail;
                        return true;
                    }
                }
            }
            break;
    }
    return false;

}

void GameObject::moveUp()
{

    if (pos.y - 2 <= currentRail.start.y) {
        pos.y = currentRail.start.y;
    } else {
        pos.y -= 2;
    }

}

void GameObject::moveDown()
{

    if (pos.y + 2 >= currentRail.end.y) {
        pos.y = currentRail.end.y;
    } else {
        pos.y += 2;
    }

}

void GameObject::moveRight()
{


    if (pos.x + 2 >= currentRail.end.x) {
        pos.x = currentRail.end.x;
    } else {
        pos.x += 2;
    }

}

void GameObject::moveLeft()
{

    if (pos.x - 2 <= currentRail.start.x) {
        pos.x = currentRail.start.x;
    } else {
        pos.x -= 2;
    }

}

void GameObject::setDirection(Direction direction)
{
    this->direction = direction;
}

void GameObject::setPreDirection(Direction direction)
{
    this->pre_direction = direction;
}

GameObject::Direction GameObject::getDirection()
{
    return direction;
}

GameObject::Direction GameObject::getPreDirection()
{
    return pre_direction;
}


