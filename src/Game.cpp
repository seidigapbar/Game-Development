#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Game.h"

bool Game::init(const char *title, int xpos, int ypos, int height, int width, int flags) 
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		running_pWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);
		if (running_pWindow != 0) 
		{
			running_pRenderer = SDL_CreateRenderer(running_pWindow, -1, 0);
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
	SDL_RenderPresent(running_pRenderer);
}
void Game::update() {}

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
		default:
			break;
		}
	}
}
void Game::clean() 
{
	SDL_DestroyRenderer(running_pRenderer);
	SDL_DestroyWindow(running_pWindow);
}

bool Game::isRunning() { return is_running; }


//Trying to understand how the things are rendered. So far not successful
bool Game::createSprite()
{
	SDL_Rect m_sourceRectangle;
	SDL_Rect m_destinationRectangle;
	SDL_Surface *image;
	SDL_RWops *rwop;
	rwop = SDL_RWFromFile("assets/pixelman.png", "r");
	image = IMG_LoadPNM_RW(rwop);
	SDL_Texture* pixelman_Texture = SDL_CreateTextureFromSurface(this->running_pRenderer, image);
	SDL_FreeSurface(image);

	SDL_QueryTexture(pixelman_Texture, NULL, NULL,
	&m_sourceRectangle.w, &m_sourceRectangle.h);


	m_destinationRectangle.x = m_sourceRectangle.x = 0;
	m_destinationRectangle.w = m_sourceRectangle.w;
	m_destinationRectangle.h = m_sourceRectangle.h;
	m_destinationRectangle.y = m_sourceRectangle.y = 0;

	SDL_RenderCopy(this->running_pRenderer, pixelman_Texture, &m_sourceRectangle,
	&m_destinationRectangle);

	return true;
}