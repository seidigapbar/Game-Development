#include <SDL2/SDL.h>
#include <SDL_image.h>
#include "Game.h"

bool Game::init(const char *title, int xpos, int ypos, int height, int width, int flags) 
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		running_pWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);
		if (running_pWindow != 0) 
		{
			running_pRenderer = SDL_CreateRenderer(running_pWindow, -1, 0);
			TheTextureManager::Instance()->load("assets/Walk2.png", "animate", running_pRenderer);
			this->main_character = new Character("assets/Walk2.png", "main character", 220, 140, running_pRenderer);
			this->main_character->displayOnScreen(this->current_frame);

			is_running = true;			
			return true;
		}
	}
	return false;
}

void Game::render() 
{
	SDL_SetRenderDrawColor(running_pRenderer, 0, 0, 0, 255);
	SDL_RenderClear(running_pRenderer);
	//main_character->displayOnScreen();
	//TheTextureManager::Instance()->draw("main character", 220, 140, 100, 100, running_pRenderer);
	//TheTextureManager::Instance()->drawFrame("animate", 100, 100, 72, 72, 1, current_frame, running_pRenderer);
	this->main_character->displayOnScreen(this->current_frame);
	SDL_RenderPresent(running_pRenderer);
}
void Game::update() {
	current_frame = int(SDL_GetTicks() / 100);
}

void Game::handleEvents() 
{
	SDL_Event event;
	if (SDL_PollEvent(&event)) 
	{
		switch (event.type) 
		{
		case SDL_QUIT:
			is_running = false;
			break;
		case SDL_KEYDOWN:
			this->main_character->handleInput(this->current_frame);
			break;
		default:
			break;
		}
	}
}
void Game::clean() 
{
	SDL_DestroyRenderer(running_pRenderer);
	SDL_DestroyWindow(running_pWindow);
	delete this->main_character;
	this->main_character = NULL;
}

bool Game::isRunning() { return is_running; }