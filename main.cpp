#include <iostream>
#include "Screen.h"
#include "GameManager.h"
#include <ctime>

int main(int argv, char **args)
{
    srand(time(nullptr));
    Screen::getInstance();
    GameManager::getInstance()->runGame();
    bool newGame = true;
    while (newGame) {
        SDL_Event event;
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYDOWN) {
                if (SDL_HasEvent(SDL_QUIT) || event.key.keysym.sym == SDLK_ESCAPE) {
                    newGame = false;
                    Screen::deleteInstance();
                } else if (event.key.keysym.sym == SDLK_RETURN) {
                    GameManager::getInstance()->runGame();
                    GameManager::deleteInstance();
                }
            }
        }
    }
    return 0;

}
