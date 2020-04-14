#include <iostream>
#include "Screen.h"
#include "GameManager.h"
#include <ctime>

int main(int argv, char** args) {
    srand(time(NULL));
    Screen::getInstance();
    GameManager::getInstance()->runGame();
    return 0;

}
