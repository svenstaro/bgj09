#include "main_state.hpp"
#include "system_movement.hpp"
#include "system_draw.hpp"
#include "system_controls.hpp"
#include "entityx/entityx.h"
#include <SDL2/SDL.h>

MainState::MainState(Game *game) : m_game(game) {}

MainState::~MainState(){}

int MainState::init() {
	m_systems.add<MovementSystem>();
	m_systems.add<DrawSystem>(m_game);
    m_systems.add<ControlSystem>();
    return 0;
}

void MainState::update(double dt) {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            m_game->shutdown();
        }
        if (e.type == SDL_KEYDOWN) {
            if(e.key.keysym.sym == SDLK_ESCAPE) {
                m_game->shutdown();
            }
        }
    }

    SDL_SetRenderDrawColor(m_game->get_renderer(), 0, 100, 200, 255);
    SDL_RenderClear(m_game->get_renderer());
    SDL_RenderPresent(m_game->get_renderer());

    m_systems.update<MovementSystem>(dt);
    m_systems.update<DrawSystem>(dt);
}
