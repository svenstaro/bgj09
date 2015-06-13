#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#include "entityx/entityx.h"
#include "component_interactable.hpp"
#include "component_position.hpp"
#include "component_moveable.hpp"

#include <glm/vec2.hpp>
#include <SDL2/SDL.h>

#include <iostream>
#include <random>
#include <functional>

std::default_random_engine random_engine;
std::uniform_int_distribution<int> distribution{0, 255};
auto rand_color = std::bind(distribution, random_engine);

SDL_Window *win;
SDL_Renderer *ren;

entityx::EntityX ex;

entityx::Entity entity = ex.entities.create();


void mainloop() {
    SDL_SetRenderDrawColor(ren, rand_color(), rand_color(), rand_color(), 255);
    SDL_RenderClear(ren);
    SDL_RenderPresent(ren);
    SDL_Delay(1000);
}

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if (win == nullptr){
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == nullptr){
        SDL_DestroyWindow(win);
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }
    entity.assign<Interactable>();
    entity.assign<Position>();
    entity.assign<Movable>();
    //entity.assign<Drawable>();

#ifdef __EMSCRIPTEN__
    emscripten_set_main_loop(mainloop, 0, true);
#else
    auto lol = 5;
    while (lol > 0) {
        mainloop();
        --lol;
    }
#endif

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}
