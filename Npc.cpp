//
// Created by fredr on 08.04.2020.
//

#include "Npc.h"


Npc::Npc(const char *path, SDL_Point pos) : GameObject(path, pos)
{}

Npc::~Npc()
{}


void Npc::move()
{
    if (path.empty()) {
        path = findPath(pos, destination);
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

bool Npc::isValidPoint(SDL_Point point)
{
    for (Rails rail : arrayOfRails) {
        if (rail == point)
            return true;
    }
    return false;
}

std::vector<SDL_Point> Npc::findPath(SDL_Point start, SDL_Point dest)
{

    Rails rail;

    for (Rails currRail : arrayOfRails) {
        if (currRail == dest) {
            rail = currRail;
            break;
        }
    }

    std::vector<SDL_Point> stack;
    std::set<SDL_Point *> alreadyVisted;

    if (!isValidPoint(start) || !isValidPoint(dest))
        return stack;

    if (&dest == start) {
        return stack;
    }


    calculatePath(stack, alreadyVisted, start, rail);

    if (isPathTo(stack, rail)) {
        stack.emplace_back(dest);
        std::reverse(stack.begin(), stack.end());
        stack.pop_back();
        return stack;
    }

    stack.clear();
    return stack;

}


bool Npc::isPointIn(std::set<SDL_Point *> alreadyVisted, SDL_Point point)
{
    for (SDL_Point *point2 : alreadyVisted) {
        if (point2 == point)
            return true;
    }
    return false;
}

void
Npc::calculatePath(std::vector<SDL_Point> &stack, std::set<SDL_Point *> &alreadyVisted, SDL_Point current, Rails rail)
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

bool Npc::isPathTo(std::vector<SDL_Point> &stack, Rails rail)
{
    if (!stack.empty()) {
        if (rail == stack.back())
            return true;
    }
    return false;
}


std::vector<SDL_Point> Npc::getAdjacents(SDL_Point point)
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


void Npc::moveUp()
{
    if (pos.y - 2 < goal.y) {
        pos.y = goal.y;
    } else
        pos.y -= 2;
}

void Npc::moveDown()
{
    if (pos.y + 2 > goal.y)
        pos.y = goal.y;
    else
        pos.y += 2;
}

void Npc::moveRight()
{
    if (pos.x + 2 > goal.x)
        pos.x = goal.x;
    else
        pos.x += 2;
}

void Npc::moveLeft()
{
    if (pos.x - 2 < goal.x)
        pos.x = goal.x;
    else
        pos.x -= 2;
}

void Npc::update()
{
    GameObject::update();
    checkCollision();
}

void Npc::checkCollision()
{
    SDL_Rect pacmanRect = Pacman::getInstance()->getRect();
    if(SDL_HasIntersection(&destRect, &pacmanRect)) {
        Pacman::getInstance()->decrementHp();
        findNewLocation();
    }
}

void Npc::findNewLocation()
{
    int randNum = rand() % 92;
    SDL_Point dest = arrayOfRails[randNum].end;
    std::vector<SDL_Point> newPath = findPath(Pacman::getInstance()->getPosition(), dest);
    if(newPath.size() < 25) {
        findNewLocation();
    }
    Pacman::getInstance()->setPosition(newPath[0]);
}
