//
// Created by fredr on 31.03.2020.
//

#ifndef PACMAN_GAMEMANAGER_H
#define PACMAN_GAMEMANAGER_H

#include "Screen.h"
#include "GameObject.h"
#include "Pacman.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>


class GameManager {

public:

    static GameManager *getInstance();

    static void deleteInstance();

    void runGame();

    void handleEvents();
    void update();
    void render();
    void clean();
    enum Direction{LEFT, RIGHT, UP, DOWN, STOP};


private:

    static GameManager *instance;
    Direction direction;
    Uint32 frameStart;
    int frameTime;
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    Pacman *pacman = Pacman::getInstance();
    bool isRunning;
    GameManager();
    ~GameManager();


};


#endif //PACMAN_GAMEMANAGER_H
