#include "main_state.hpp"
#include "system_movement.hpp"
#include "system_draw.hpp"
#include "system_controls.hpp"
#include "system_collision.hpp"
#include "system_enemy.hpp"

#include "entityx/entityx.h"

#include <SDL2/SDL.h>

MainState::MainState(Game *game) : m_game(game) {}

MainState::~MainState() {}

int MainState::init() {
    m_systems.add<MovementSystem>(m_game);
    m_systems.add<DrawSystem>(m_game);
    m_systems.add<ControlSystem>();
    m_systems.add<CollisionSystem>(m_game);
    m_systems.add<EnemySystem>();
    m_systems.configure();

    EntityCreator::create_level_1(m_entities);
    EntityCreator::create_angler(m_entities);
    EntityCreator::create_enemy(m_entities);

    Mix_PlayMusic(m_game->get_res_manager().get_music("music1"), -1);

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

    int score = m_game->get_score() + (int)(dt * 1000);
    m_game->set_score(score);

    if (score > enemies * 5000) {
            EntityCreator::create_enemy(m_entities);
            ++enemies;
    }

    m_systems.update<MovementSystem>(dt);
    m_systems.update<DrawSystem>(dt);
    m_systems.update<ControlSystem>(dt);
    m_systems.update<CollisionSystem>(dt);
    m_systems.update<EnemySystem>(dt);
}
