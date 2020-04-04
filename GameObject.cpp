//
// Created by fredr on 01.04.2020.
//

#include "GameObject.h"
#include "Screen.h"

GameObject::GameObject(const char *path, int x, int y) : objTexture(Screen::loadImage(path, 255)),
                                                         renderer(Screen::renderer), direction(LEFT),
                                                         pre_direction(STOP), xpos(x), ypos(y),
                                                         arrayOfRails(Map::getInstance()->getRails())

{}

GameObject::~GameObject()
{}

void GameObject::update()
{

    srcRect.h = 23;
    srcRect.w = 23;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w;
    destRect.h = srcRect.h;



    if(xpos == 100 && ypos == 215 && direction == LEFT) {
        xpos = 515;
    } else if (xpos == 515 && ypos == 215 && direction == RIGHT) {
        xpos = 100;
    }




    if (checkRail(direction)) {

        switch (direction) {
            case LEFT:
                moveLeft();
                break;
            case RIGHT:
                moveRight();
                break;
            case UP:
                moveUp();
                break;
            case DOWN:
                moveDown();
                break;
            default:
                break;
        }
        pre_direction = STOP;

    } else if (checkRail(pre_direction)) {

        switch (pre_direction) {
            case LEFT:
                moveLeft();
                break;
            case RIGHT:
                moveRight();
                break;
            case UP:
                moveUp();
                break;
            case DOWN:
                moveDown();
                break;
            default:
                break;
        }
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
                if (ypos >= rail.y1 && ypos < rail.y2) {
                    if (xpos == rail.x1) {
                        currentRail = &rail;
                        return true;
                    }
                }
            }
            break;
        case UP:
            for (Rails rail : arrayOfRails) {
                if (ypos > rail.y1 && ypos <= rail.y2) {
                    if (xpos == rail.x1) {
                        currentRail = &rail;
                        return true;
                    }
                }
            }
            break;
        case LEFT:
            for (Rails rail : arrayOfRails) {
                if (xpos > rail.x1 && xpos <= rail.x2) {
                    if (ypos == rail.y1) {
                        currentRail = &rail;
                        return true;
                    }
                }
            }
            break;
        case RIGHT:
            for (Rails rail : arrayOfRails) {
                if (xpos >= rail.x1 && xpos < rail.x2) {
                    if (ypos == rail.y1) {
                        currentRail = &rail;
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

    if (ypos - 2 <= currentRail->y1) {
        ypos = currentRail->y1;
    } else {
        ypos -= 2;
    }

}

void GameObject::moveDown()
{

    if (ypos + 2 >= currentRail->y2) {
        ypos = currentRail->y2;
    } else {
        ypos += 2;
    }

}

void GameObject::moveRight()
{


    if (xpos + 2 >= currentRail->x2) {
        xpos = currentRail->x2;
    } else {
        xpos += 2;
    }

}

void GameObject::moveLeft()
{

    if (xpos - 2 <= currentRail->x1) {
        xpos = currentRail->x1;
    } else {
        xpos -= 2;
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

