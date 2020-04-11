//
// Created by fredr on 31.03.2020.
//

#ifndef PACMAN_GAMEMANAGER_H
#define PACMAN_GAMEMANAGER_H

#include "Screen.h"
#include "Pacman.h"
#include <vector>
#include "Map.h"
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
    enum Direction{};


private:

    static GameManager *instance;
    bool isRunning;
    Uint32 frameStart;
    int frameTime;
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Direction direction;
    Pacman *pacman = Pacman::getInstance();
    std::vector<GameObject*> gameObjects;


    GameManager();
    ~GameManager();


};


#endif //PACMAN_GAMEMANAGER_H
