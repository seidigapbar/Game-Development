#pragma once
#ifndef __Game__
#define __Game__ 

#include "SDL2/SDL.h"

class Game 
{
public:
    Game() = default;
    ~Game() = default;
    bool init(const char *title, int xpos, int ypos, int height, int width, int flags);
    void render();
    void update();
    bool createSprite();
    void handleEvents();
    void clean();
    bool isRunning();
    private: 
    SDL_Window* running_pWindow;
    SDL_Renderer* running_pRenderer;
    bool is_running;

};

#endif