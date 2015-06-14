#include "gameover_state.hpp"
#include "main_state.hpp"

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
            if(e.key.keysym.sym == SDLK_SPACE){
                //m_game->popstate();
                //m_game->popstate();
                //m_game->get_states().push({"main", std::make_unique<MainState>(m_game)});
                //m_game->get_states().top().second->init();
            }
        }
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
    SDL_Color color{200, 100, 0, 200};
    SDL_Surface *font_surf = TTF_RenderText_Blended(m_game->get_res_manager().get_font("font20"), "Game Over :(", color);
    SDL_Texture *font_tex = SDL_CreateTextureFromSurface(m_game->get_renderer(), font_surf);
    SDL_RenderCopy(m_game->get_renderer(), font_tex, nullptr, nullptr);
    SDL_FreeSurface(font_surf);
    SDL_DestroyTexture(font_tex);
    SDL_RenderPresent(m_game->get_renderer());
}
