#include "game.hpp"

#include "main_state.hpp"
#include "entity_creator.hpp"

Game::~Game() {
    SDL_CloseAudio();
    SDL_DestroyRenderer(m_render);
    SDL_DestroyWindow(m_window);
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}

int Game::init() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    int width = 1200;
    int height = 800;

    m_window = SDL_CreateWindow("Hello World!", 100, 100, width, height, SDL_WINDOW_SHOWN);
    if (m_window == nullptr) {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    m_render = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (m_render == nullptr) {
        SDL_DestroyWindow(m_window);
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    if (Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) != 0) {
        std::cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
        return 1;
    }

    m_res_manager.load_texture("Player","res/character.png", m_render);
    m_res_manager.load_texture("level_1_bg","res/underwater_mountains.png", m_render);
    m_res_manager.load_texture("gradient","res/gradient.png", m_render);
    m_res_manager.load_texture("enemy","res/jellyfish-md.png", m_render);
    m_res_manager.load_texture("enemy","res/jellyfish-md.png", m_render);

    SDL_RenderSetLogicalSize(m_render, width, height);

    entityx::Entity entity = m_ex.entities.create();
    entity.assign<Interactable>();
    entity.assign<Position>();

    m_states.push({"main", std::make_unique<MainState>(this)});
    m_states.top().second->init();

    return 0;
}

void Game::mainloop() {
    int current_time = SDL_GetTicks();
    double dt = (current_time - m_last_frame_time) / 1000.0;
    m_last_frame_time = current_time;

    m_states.top().second->update(dt);
}

SDL_Renderer *Game::get_renderer() {
    return m_render;
}

SDL_Window *Game::get_window() {
    return m_window;
}

ResourceManager &Game::get_res_manager() {
    return m_res_manager;
}

bool Game::is_running() {
    return m_running;
}

void Game::shutdown() {
    m_running = false;
}

const SDL_Rect &Game::get_worldsize() const {
    return m_worldsize;
}
