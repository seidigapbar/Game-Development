#include <iostream>
#include <SDL2/SDL.h>
#include <vector>

const int WINDOW_WIDTH = 512;
const int WINDOW_HEIGHT = 284;
SDL_Window*g_main_window;
SDL_Renderer*g_main_renderer;

SDL_Texture *newTexture;

namespace Colors {
    const SDL_Color BLACK = {0, 0, 0, SDL_ALPHA_OPAQUE};
}

static bool Init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) > 0) {
        std::cout << "SDL_Init failed with error: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    g_main_window = SDL_CreateWindow(
        "C++zation", 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        WINDOW_WIDTH,
        WINDOW_HEIGHT, 
        SDL_WINDOW_OPENGL
    );

    if(g_main_window == nullptr) {
        std::cout << "Unable to create the main window. Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return EXIT_FAILURE;
    }

    g_main_renderer = SDL_CreateRenderer(g_main_window, -1, SDL_RENDERER_PRESENTVSYNC);

    return true;
}

void Shutdown() {
    if(g_main_window != nullptr) {
        SDL_DestroyWindow(g_main_window);
        g_main_window = nullptr;
    }

    if (g_main_renderer != nullptr) {
        SDL_DestroyRenderer(g_main_renderer);
        g_main_renderer = nullptr;
    }

    SDL_Quit();
}

static void ClearScreen(SDL_Renderer* renderer) {
     SDL_SetRenderDrawColor(renderer, Colors::BLACK.r, Colors::BLACK.g, Colors::BLACK.b, Colors::BLACK.a);
     SDL_RenderClear(renderer);
}

int main()
{
    if(Init() == false) { Shutdown(); }

    SDL_Event event;
    bool running = true;

    while(running) {
        ClearScreen(g_main_renderer);

        if(SDL_PollEvent(&event)) {
            switch (event.type)
            {
            case SDL_KEYDOWN: {
                running = event.key.keysym.scancode != SDL_SCANCODE_ESCAPE;
                break;
            }
            case SDL_QUIT: {
                running = false;
                break;
            }
            default:
                break;
            }
        }
        SDL_RenderPresent(g_main_renderer);
    }

    Shutdown();
    return EXIT_SUCCESS;
}