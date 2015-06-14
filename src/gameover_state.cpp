#include "gameover_state.hpp"

#include "strapon/resource_manager/resource_manager.hpp"

GameoverState::GameoverState(Game *game) :
    m_game(game) {}

GameoverState::~GameoverState() {}

int GameoverState::init() {
    return 0;
}

void GameoverState::update(double dt) {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_KEYDOWN) {
            if(e.key.keysym.sym == SDLK_SPACE) {
                m_game->popstate();
            }
        }
    }
}
