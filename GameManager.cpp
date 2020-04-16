//
// Created by fredr on 31.03.2020.
//

#include "GameManager.h"


GameManager *GameManager::instance = nullptr;

GameManager *GameManager::getInstance()
{
    if (!instance)
        instance = new GameManager;
    return instance;
}

void GameManager::deleteInstance()
{
    if (instance) {
        delete instance;
        instance = nullptr;
    }
}

GameManager::GameManager() : isRunning(true)
{
    Map::getInstance();
    Map::getInstance()->initPills();
    for (Pill *pill : Map::getInstance()->getPills()) {
        pills.emplace_back(pill);
    }
    players.emplace_back(pacman);
    players.emplace_back(Blinky::getInstance());
    players.emplace_back(Clyde::getInstance());
    players.emplace_back(Pinky::getInstance());
    players.emplace_back(Inky::getInstance());
}

GameManager::~GameManager()
{}

void GameManager::runGame()
{

    while (isRunning) {

        frameStart = SDL_GetTicks();

        handleEvents();
        update();
        render();
        checkFrameRate();
    }

    clean();
}

void GameManager::checkFrameRate()
{
    frameTime = SDL_GetTicks() - frameStart;

    if (frameDelay > frameTime) {
        SDL_Delay(frameDelay - frameTime);
    }
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

    for (auto &player : players) {
        player->update();
        player->move();
    }


    int index = 0;
    for (auto &pill : pills) {
        pill->update();
        index++;
    }

    pills.erase(std::remove_if(
            pills.begin(),
            pills.end(),
            [](GameObject *pill) -> bool {
                return !pill->isStillAlive();
            }
                ),
                pills.end()
    );

    if (pacmanHp < 1) {
        isRunning = false;
    }

    if (pills.empty()) {
        isRunning = false;
    }

    if(hasCollided) {
        pacmanHp--;
        players.clear();
        pacman->deleteInstance();
        Blinky::deleteInstance();
        Pinky::deleteInstance();
        Inky::deleteInstance();
        Clyde::deleteInstance();
        pacman = Pacman::getInstance();
        players.emplace_back(pacman);
        players.emplace_back(Blinky::getInstance());
        players.emplace_back(Clyde::getInstance());
        players.emplace_back(Pinky::getInstance());
        players.emplace_back(Inky::getInstance());
        hasCollided = false;
    }

}

void GameManager::render()
{

    SDL_RenderClear(Screen::renderer);

    Map::getInstance()->renderMap();
    char str[10];
    sprintf(str, "%s%d", "Pacmans HP: ", pacmanHp);
    Screen::drawText(15, SDL_Color{255, 255, 255}, str, SDL_Point{400, 460});


    for (auto &pill : pills) {
        pill->render();
    }
    for (auto &player : players) {
        player->render();
    }

    if (!isRunning) {

        if(pills.empty()) {
            Screen::drawText(40, {0, 255, 0}, "You win!", {280, 210});
        } else {
        Screen::drawText(40, {255, 0, 0}, "Game over", {280, 210});
        }
        Screen::drawText(20, {255, 255, 255}, "Press enter to play agian or escape to quit", {100, 260});
    }

    SDL_RenderPresent(Screen::renderer);
}

void GameManager::setHasCollided()
{
    hasCollided = true;
}

void GameManager::clean()
{
    Map::deleteInstance();
    players.clear();
    pills.clear();
    pacman->deleteInstance();
    Blinky::deleteInstance();
    Inky::deleteInstance();
    Pinky::deleteInstance();
    Clyde::deleteInstance();
    deleteInstance();
}











