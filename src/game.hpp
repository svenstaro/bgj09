#ifndef GAME_HPP
#define GAME_HPP

#include "component_interactable.hpp"
#include "component_position.hpp"
#include "entity_creator.hpp"

#include "strapon/state/state.hpp"
#include "strapon/resource_manager/resource_manager.hpp"

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
    void shutdown();
    void gameover();
    void popstate();
    int get_score();
    void set_score(int score);
    std::stack<std::pair<std::string, std::unique_ptr<State>>> &get_states();
    const std::string &statename() const;

    SDL_Renderer *get_renderer();
	ResourceManager &get_res_manager();
    SDL_Window *get_window();
    const SDL_Rect &get_worldsize() const;

private:
    bool m_running = true;
    int m_last_frame_time = 0;
    SDL_Rect m_worldsize = {0, 0, 1600 , 1200};

    SDL_Renderer *m_render;
    SDL_Window *m_window;
    std::stack<std::pair<std::string, std::unique_ptr<State>>> m_states;
    entityx::EntityX m_ex;
    ResourceManager m_res_manager;
    int m_score = 0;
};

#endif /* end of include guard: GAME_HPP */
