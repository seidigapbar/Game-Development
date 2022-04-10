#include "Characters.h"
#include "Texture.h"

Character::Character(std::string path, std::string name, int x, int y, SDL_Renderer* running_pRenderer)
    : path(path), name(name), running_pRenderer(running_pRenderer), max_health(100)
{ 
    position.first = x; 
    position.second = y;     
    TheTextureManager::Instance()->load(this->path, this->name, this->running_pRenderer);
}

bool Character::displayOnScreen(int current_frame)
{
    current_frame = current_frame % 4;
    SDL_SetRenderDrawColor(this->running_pRenderer, 0, 0, 0, 255);
    SDL_RenderClear(this->running_pRenderer);
    TheTextureManager::Instance()->drawFrame(this->name, this->position.first, this->position.second, 72, 72, 1, current_frame, this->running_pRenderer);
    SDL_RenderPresent(this->running_pRenderer);
}

void Character::handleInput(int current_frame){
    this->keystate = SDL_GetKeyboardState(NULL);
    //Very very ugly code
    if(keystate[SDL_SCANCODE_DOWN] == 1)
        this->goDown();
    else if(keystate[SDL_SCANCODE_UP] == 1)
        this->goUp();
    else if(keystate[SDL_SCANCODE_LEFT] == 1)
        this->goLeft();
    else if(keystate[SDL_SCANCODE_RIGHT] == 1)
        this->goRight();
    else
        return;
    current_frame = current_frame % 6;
    SDL_SetRenderDrawColor(this->running_pRenderer, 0, 0, 0, 255);
    SDL_RenderClear(this->running_pRenderer);
    TheTextureManager::Instance()->drawFrame(this->name, this->position.first, this->position.second, 72, 72, 1, current_frame, running_pRenderer);
    SDL_RenderPresent(this->running_pRenderer);

}


//Very very ugly code
void Character::goUp(){
    this->position.second += 7;
}

void Character::goDown(){
    this->position.second -= 7;
}

void Character::goLeft(){
    this->position.first -= 7;
}

void Character::goRight(){
    this->position.first += 7;
}