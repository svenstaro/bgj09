#include "main_state.hpp"

#include <SDL2/SDL.h>

MainState::MainState(Game *game) : m_game(game) {}

int MainState::init() {
    return 0;
}

void MainState::update(float dt) {
    SDL_SetRenderDrawColor(game->get_renderer(), 0, 100, 200, 255);
    SDL_RenderClear(game->get_renderer());
    SDL_RenderPresent(game->get_renderer());
}
