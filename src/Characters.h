#pragma once
#ifndef __CHARACTERS__
#define __CHARACTERS__

#include <utility>
#include <string>
#include "SDL2/SDL.h"
#include "SDL_image.h"

class Character{
public:
Character() = default;
Character(std::string path, std::string name, int x, int y, SDL_Renderer* running_pRenderer);
~Character() = default;
bool displayOnScreen(int current_frame);
void handleInput(int current_frame);

private:
const int max_health;
int health;
std::pair<int, int> Direction, position;
std::string path, name;
const Uint8* keystate;
SDL_Renderer* running_pRenderer;
void goUp();
void goDown();
void goLeft();
void goRight();
};

#endif