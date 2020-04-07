//
// Created by fredr on 01.04.2020.
//

#include "GameObject.h"
#include "Map.h"
#include "Pacman.h"

GameObject::GameObject(const char *path, SDL_Point pos) : objTexture(Screen::loadImage(path, 255)),
                                                          renderer(Screen::renderer), pos(pos),
                                                          arrayOfRails(Map::getInstance()->getRails())
{
}

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
    SDL_Point pacmanPos = Pacman::getInstance()->getPosition();
    if (&pacmanPos == pos) {
        path.clear();
        return;
    }
    Rails *temp = Pacman::getInstance()->getCurrentRail();
    Rails *pacmanRail = new Rails(temp->start, temp->end);
    if (path.empty()) {
        path.clear();
        path = findPath(pos, pacmanPos, pacmanRail);
        if (path.empty())
            return;
    }

    if (!path.empty()) {
        goal = path.back();
        if (pos.x == goal.x) {
            if (pos.y < goal.y) {
                moveDown();
            } else {
                moveUp();
            }
        } else if (pos.y == goal.y) {
            if (pos.x > goal.x) {
                moveLeft();
            } else {
                moveRight();
            }
        }
    } else {
        std::cout << "Not finding point" << std::endl;
    }

    if (&pos == goal)
        path.pop_back();
}

bool GameObject::isValidPoint(SDL_Point point)
{
    for (Rails rail : arrayOfRails) {
        if (rail == point)
            return true;
    }
    return false;
}

std::vector<SDL_Point> GameObject::findPath(SDL_Point start, SDL_Point dest, Rails *rail)
{

    std::vector<SDL_Point> stack;
    std::set<SDL_Point *> alreadyVisted;

    if (!isValidPoint(start) || !isValidPoint(dest))
        return stack;

    if (*rail == start) {
        stack.emplace_back(dest);
        return stack;
    }


    calculatePath(stack, alreadyVisted, start, *rail);

    if (isPathTo(stack, *rail)) {
        stack.emplace_back(dest);
        std::reverse(stack.begin(), stack.end());
        stack.pop_back();
        return stack;
    }

    stack.clear();
    return stack;

}


bool GameObject::isPointIn(std::set<SDL_Point *> alreadyVisted, SDL_Point point)
{
    for (SDL_Point *point2 : alreadyVisted) {
        if (point2 == point)
            return true;
    }
    return false;
}

void GameObject::calculatePath(std::vector<SDL_Point> &stack, std::set<SDL_Point *> &alreadyVisted, SDL_Point current,
                           Rails rail)
{
    stack.emplace_back(current);
    alreadyVisted.insert(&current);

    if (isPathTo(stack, rail))
        return;

    for (SDL_Point &adjacent : getAdjacents(current)) {
        if (isPointIn(alreadyVisted, adjacent)) {
            continue;
        }

        calculatePath(stack, alreadyVisted, adjacent, rail);

        if (!isPathTo(stack, rail)) {
            stack.pop_back();
        } else {
            return;
        }
    }
}

bool GameObject::isPathTo(std::vector<SDL_Point> &stack, Rails rail)
{
    if (!stack.empty()) {
        if (rail == stack.back())
            return true;
    }
    return false;
}


std::vector<SDL_Point> GameObject::getAdjacents(SDL_Point point)
{
    std::vector<SDL_Point> points;
    if (&point == teleportRight) {
        points.emplace_back(SDL_Point{207, 215});
    } else if (&point == teleportLeft) {
        points.emplace_back(SDL_Point{412, 215});
    }

    for (Rails rail : arrayOfRails) {
        if (&point == rail.start) {
            points.emplace_back(rail.end);
        } else if (&point == rail.end) {
            points.emplace_back(rail.start);
        } else if (rail == point) {
            points.emplace_back(rail.end);
        }
    }

    return points;
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



