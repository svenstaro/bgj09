#ifndef GAME_HPP
#define GAME_HPP

#include "component_interactable.hpp"
#include "component_position.hpp"
#include "strapon/resource_manager/resource_manager.hpp"

#include "strapon/state/state.hpp"

#include "entityx/entityx.h"

#include <glm/vec2.hpp>
#include <SDL2/SDL.h>

#include <iostream>
#include <random>
#include <memory>
#include <functional>
#include <stack>
#include <string>

class Game {
public:
    ~Game();

    int init();
    void mainloop();
    bool is_running();
    SDL_Renderer *get_renderer();
	ResourceManager *get_res_manager();

private:
    bool m_running = true;
    int m_last_frame_time = 0;

    SDL_Window *m_window;
    SDL_Renderer *m_render;
    std::stack<std::pair<std::string, std::unique_ptr<State>>> m_states;
    entityx::EntityX m_ex;
    ResourceManager *m_res_manager;
};

#endif /* end of include guard: GAME_HPP */
