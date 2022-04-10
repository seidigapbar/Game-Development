#include <SDL2/SDL.h>
#include <memory>
#include "Game.h"

/*//Needs to be removed. Put it here until I resolve how to solve the compiler issues w/ visual studio
template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}*/

int main(int argc, char *argv[]) {
    
    std::unique_ptr<Game> running_pGame = std::make_unique<Game>();
	
    running_pGame->init("ShootingGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
	while (running_pGame->isRunning())
	{
		running_pGame->handleEvents();
		running_pGame->update();
		running_pGame->render();		
	}
	running_pGame->clean();
	return 0;
}