#include <iostream>
#include "Screen.h"
#include "GameManager.h"

int main(int argv, char** args) {
    Screen::getInstance();
    GameManager::getInstance()->runGame();
    return 0;

}
