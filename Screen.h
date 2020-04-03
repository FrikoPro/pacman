//
// Created by fredr on 30.03.2020.
//

#ifndef PACMAN_SCREEN_H
#define PACMAN_SCREEN_H


#include <SDL_video.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>


class Screen {

public:
    static Screen* getInstance();
    static void deleteInstance();

    static SDL_Texture *loadImage(const char* path, int alphaColor);
    SDL_Renderer *getRenderer() {return renderer;}

    static SDL_Renderer *renderer;

private:
    Screen();
    ~Screen();
    static Screen* instance;
    SDL_Window* window;
};


#endif //PACMAN_SCREEN_H
