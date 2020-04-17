//
// Created by fredr on 08.04.2020.
//

#ifndef PACMAN_NPC_H
#define PACMAN_NPC_H

#include "GameObject.h"
#include "Pacman.h"
#include <set>
#include <algorithm>

class Npc : public GameObject {

public:
    Npc(const char *path, SDL_Point pos);

    ~Npc() override;

    void moveLeft();

    void moveRight();

    void moveDown();

    void moveUp();

    void move() override;

    void update() override;

    std::vector<SDL_Point> findPath(SDL_Point start, SDL_Point dest);

    void
    calculatePath(std::vector<SDL_Point> &stack, std::vector<SDL_Point> &alreadyVisted, SDL_Point current,
                  const Rails &rail);

    std::vector<SDL_Point> getAdjacents(SDL_Point point);

    static bool isPointIn(const std::vector<SDL_Point> &alreadyVisted, SDL_Point point);

    bool isPathTo(std::vector<SDL_Point> &stack, Rails rail);

    bool isValidPoint(SDL_Point point);

    void checkCollision();

protected:

    SDL_Point destination = SDL_Point{0, 0};
    SDL_Point goal;
    std::vector<SDL_Point> path;

};


#endif //PACMAN_NPC_H
