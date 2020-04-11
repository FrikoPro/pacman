//
// Created by fredr on 31.03.2020.
//

#include "GameManager.h"
#include "Blinky.h"


GameManager *GameManager::instance = nullptr;

GameManager *GameManager::getInstance()
{
    if (!instance)
        instance = new GameManager;
    return instance;
}

void GameManager::deleteInstance()
{
    if (instance)
        delete instance;
    instance = nullptr;
}

GameManager::GameManager() : isRunning(true)
{
    Map::getInstance();
    Map::getInstance()->initPills();
    for(Pill *pill : Map::getInstance()->getPills()) {
        gameObjects.emplace_back(pill);
    }
    gameObjects.emplace_back(pacman);
    gameObjects.emplace_back(Blinky::getInstance());
}

GameManager::~GameManager()
{
    deleteInstance();
}

void GameManager::runGame()
{

    while (isRunning) {

        frameStart = SDL_GetTicks();

        handleEvents();
        update();
        render();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    clean();
}

void GameManager::handleEvents()
{
    const Uint8 *keys = nullptr;
    int numKeys;
    keys = SDL_GetKeyboardState(&numKeys);
    SDL_Event event;
    SDL_PumpEvents();

    if (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN) {
            direction = static_cast<Direction>(pacman->getPreDirection());
            pacman->setPreDirection(pacman->getDirection());
            if (keys[SDL_SCANCODE_ESCAPE] != 0) {
                isRunning = false;
            } else if (SDL_HasEvent(SDL_QUIT)) {
                isRunning = false;
            } else if (keys[SDL_SCANCODE_D] != 0) {
                pacman->setDirection(Pacman::RIGHT);
            } else if (keys[SDL_SCANCODE_W] != 0) {
                pacman->setDirection(Pacman::UP);
            } else if (keys[SDL_SCANCODE_A] != 0) {
                pacman->setDirection(Pacman::LEFT);
            } else if (keys[SDL_SCANCODE_S] != 0) {
                pacman->setDirection(Pacman::DOWN);
            }
            if (pacman->getDirection() == pacman->getPreDirection()) {
                pacman->setPreDirection(static_cast<Pacman::Direction>(direction));
            }
        }
    }
}

void GameManager::update()
{

    for (auto &object : gameObjects) {
        object->update();
        object->move();
    }

}

void GameManager::render()
{
    SDL_RenderClear(Screen::renderer);
    Map::getInstance()->renderMap();
    for (auto &player : gameObjects) {
        player->render();
    }

    SDL_RenderPresent(Screen::renderer);
}

void GameManager::clean()
{
    Screen::deleteInstance();
    Map::deleteInstance();
    gameObjects.clear();
}











