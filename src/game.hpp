#ifndef GAME_HPP
#define GAME_HPP

#include "component_interactable.hpp"
#include "component_position.hpp"

#include "strapon/state/state.hpp"

#include "entityx/entityx.h"

#include <glm/vec2.hpp>
#include <SDL2/SDL.h>

#include <iostream>
#include <random>
#include <functional>
#include <stack>

class Game {
public:
    ~Game();

    int init();
    void mainloop();
    bool is_running();

private:
    bool m_running = true;
    SDL_Window *m_window;
    SDL_Renderer *m_render;
    std::stack<State> m_states;
    entityx::EntityX m_ex;
};

#endif /* end of include guard: GAME_HPP */
