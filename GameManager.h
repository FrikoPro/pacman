//
// Created by fredr on 31.03.2020.
//

#ifndef PACMAN_GAMEMANAGER_H
#define PACMAN_GAMEMANAGER_H

#include "Screen.h"
#include "Pacman.h"
#include "Map.h"
#include "Blinky.h"
#include "Clyde.h"
#include "Inky.h"
#include "Pinky.h"
#include "Npc.h"
#include <vector>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>


class GameManager {

public:

    static GameManager *getInstance();

    static void deleteInstance();

    void runGame();

    void setHasCollided();

    void handleEvents();

    void update();

    void render();

    void clean();

    enum Direction {
    };


private:

    int pacmanHp = 3;

    static GameManager *instance;
    bool isRunning;
    bool hasCollided = false;
    Uint32 frameStart;
    int frameTime;
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Direction direction;
    Pacman *pacman = Pacman::getInstance();
    std::vector<GameObject *> players;
    std::vector<GameObject *> pills;


    GameManager();

    ~GameManager();


    void checkFrameRate();
};


#endif //PACMAN_GAMEMANAGER_H
