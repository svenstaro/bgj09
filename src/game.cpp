#include "game.hpp"

Game::~Game() {
    SDL_DestroyRenderer(m_render);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

int Game::init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    m_window = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if (m_window == nullptr){
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    m_render = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (m_render == nullptr){
        SDL_DestroyWindow(m_window);
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    entityx::Entity entity = m_ex.entities.create();
    entity.assign<Interactable>();
    entity.assign<Position>();

    return 0;
}

void Game::mainloop() {
    SDL_SetRenderDrawColor(m_render, 0, 100, 200, 255);
    SDL_RenderClear(m_render);
    SDL_RenderPresent(m_render);
}

bool Game::is_running() {
    return m_running;
}
