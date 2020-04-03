//
// Created by fredr on 30.03.2020.
//

#include "Screen.h"

Screen *Screen::instance = nullptr;
SDL_Renderer *Screen::renderer = nullptr;

const int fps = 60;

Screen *Screen::getInstance() {
    if (!instance)
        instance = new Screen();
    return instance;
}

void Screen::deleteInstance() {
    if (instance) {
        delete instance;
        instance = nullptr;
    }
}

Screen::Screen() {


    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }

    window = SDL_CreateWindow("pacman", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              640, 480, SDL_WINDOW_OPENGL);

    if(window) {
        std::cout << "Window initialised." << std::endl;

        renderer = SDL_CreateRenderer(window, -1, 0);

        if(renderer) {
            std::cout << "renderer initialised." << std::endl;
        }
    }

    atexit(Screen::deleteInstance);
}


Screen::~Screen() {

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}


SDL_Texture *Screen::loadImage(const char* path, int alphaColor) {
    SDL_Surface *temp;

    temp = IMG_Load(path);

    if (!temp) {
        std::cout << "failed to load image: " << IMG_GetError() << std::endl;
    }

    if(alphaColor != -1)
        SDL_SetColorKey(temp, SDL_TRUE, (Uint32)SDL_MapRGB(temp->format, (uint8_t)255, (uint8_t)255, (uint8_t)255));

    SDL_Texture *txTemp = SDL_CreateTextureFromSurface(Screen::renderer, temp);
    SDL_FreeSurface(temp);
    return txTemp;
}




