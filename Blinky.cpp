//
// Created by fredr on 04.04.2020.
//

#include "Blinky.h"


Blinky *Blinky::instance = nullptr;

Blinky::Blinky() : GameObject("../data/gfx/blinky_1.png", {280, 222})
{

}

Blinky::~Blinky()
{
    deleteInstance();
}

Blinky *Blinky::getInstance()
{
    if (!instance)
        instance = new Blinky;
    return instance;
}

void Blinky::deleteInstance()
{
    if (instance)
        delete instance;
    instance = nullptr;
}

void Blinky::move()
{

    GameObject::move();
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
                direction = DOWN;
                moveDown();
            } else {
                direction = UP;
                moveUp();
            }
        } else if (pos.y == goal.y) {
            if (pos.x > goal.x) {
                direction = LEFT;
                moveLeft();
            } else {
                direction = RIGHT;
                moveRight();
            }
        }
    } else {
        std::cout << "Not finding point" << std::endl;
    }

    if (&pos == goal)
        path.pop_back();
}

bool Blinky::isValidPoint(SDL_Point point)
{
    for (Rails rail : arrayOfRails) {
        if (rail == point)
            return true;
    }
    return false;
}

std::vector<SDL_Point> Blinky::findPath(SDL_Point start, SDL_Point dest, Rails *rail)
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


bool Blinky::isPointIn(std::set<SDL_Point *> alreadyVisted, SDL_Point point)
{
    for (SDL_Point *point2 : alreadyVisted) {
        if (point2 == point)
            return true;
    }
    return false;
}

void Blinky::calculatePath(std::vector<SDL_Point> &stack, std::set<SDL_Point *> &alreadyVisted, SDL_Point current,
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

bool Blinky::isPathTo(std::vector<SDL_Point> &stack, Rails rail)
{
    if (!stack.empty()) {
        if (rail == stack.back())
            return true;
    }
    return false;
}


std::vector<SDL_Point> Blinky::getAdjacents(SDL_Point point)
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


