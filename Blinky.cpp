//
// Created by fredr on 04.04.2020.
//

#include "Blinky.h"

Blinky *Blinky::instance = nullptr;

Blinky::Blinky() : GameObject("../data/gfx/blinky_1.png", 280, 222)
{
    direction = RIGHT;
    checkRail(direction);

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

inline bool operator==(SDL_Point const *obj1, SDL_Point const &obj2)
{
    if (obj1->x == obj2.x && obj1->y == obj2.y) {
        return true;
    } else
        return false;
}

void Blinky::move()
{
    GameObject::move();
    SDL_Point pacmanPos = Pacman::getInstance()->getPosition();
    if (path.empty()) {
        path = findPath(position, pacmanPos);
        if (path.empty())
            return;
        goal = path.back();
    }

    if (&position == goal)
        path.pop_back();

    if (!path.empty()) {
        goal = path.back();


        if (xpos == goal.x) {
            if (ypos < goal.y) {
                direction = DOWN;
                checkRail(direction);
                moveDown();
            } else {
                direction = UP;
                checkRail(direction);
                moveUp();
            }
        } else if (ypos == goal.y) {
            if (xpos > goal.x) {
                direction = LEFT;
                checkRail(direction);
                moveLeft();
            } else {
                direction = RIGHT;
                checkRail(direction);
                moveRight();
            }
        }
    } else {
        std::cout << "Not finding point" << std::endl;
    }


}

bool Blinky::isValidPoint(SDL_Point point)
{
    for (Rails rail : arrayOfRails) {
        if ((rail.x1 == point.x && rail.y1 == point.y) ||
            (rail.x2 == point.x && rail.y2 == point.y))
            return true;
    }
    return false;
}

std::vector<SDL_Point> Blinky::findPath(SDL_Point start, SDL_Point dest)
{

    std::vector<SDL_Point> stack;
    std::set<SDL_Point *> alreadyVisted;

    if (!isValidPoint(start) || !isValidPoint(dest))
        return stack;

    if (start.x == dest.x && start.y == dest.y) {
        return stack;
    }


    calculatePath(stack, alreadyVisted, start, dest);

    if (isPathTo(stack, dest)) {
        std::reverse(stack.begin(), stack.end());
        stack.pop_back();
        return stack;
    }

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
                           SDL_Point dest)
{
    stack.emplace_back(current);
    alreadyVisted.insert(&current);

    if (isPathTo(stack, dest))
        return;

    for (SDL_Point &adjacent : getAdjacents(current)) {
        if (isPointIn(alreadyVisted, adjacent)) {
            continue;
        }

        calculatePath(stack, alreadyVisted, adjacent, dest);

        if (!isPathTo(stack, dest)) {
            stack.pop_back();
        } else {
            return;
        }
    }
}

bool Blinky::isPathTo(std::vector<SDL_Point> &stack, SDL_Point dest)
{
    if (!stack.empty()) {
        if (stack.back().x == dest.x && stack.back().y == dest.y)
            return true;
    }
    return false;
}


std::vector<SDL_Point> Blinky::getAdjacents(SDL_Point point)
{
    std::vector<SDL_Point> points;
    for (Rails rail : arrayOfRails) {
        if (point.x == rail.x1 && point.y == rail.y1) {
            points.emplace_back(SDL_Point{rail.x2, rail.y2});
        } else if (point.x == rail.x2 && point.y == rail.y2) {
            points.emplace_back(SDL_Point{rail.x1, rail.y1});
        }
    }

    return points;
}


