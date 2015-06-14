#include "game.hpp"
#include "component_drawable.hpp"
#include "component_position.hpp"
#include "component_controlable.hpp"

#include "strapon/resource_manager/resource_manager.hpp"

#include "entityx/entityx.h"
#include <glm/vec2.hpp>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class DrawSystem : public entityx::System<DrawSystem>
{
public:
    DrawSystem(Game *game) : m_game(game) {
        int w, h;
        SDL_RenderGetLogicalSize(game->get_renderer(), &w, &h);
        m_camera = SDL_Rect{0, 0, w, h};
        m_drawtex = SDL_CreateTexture(game->get_renderer(), SDL_PIXELTYPE_UNKNOWN, SDL_TEXTUREACCESS_TARGET, game->get_worldsize().w, game->get_worldsize().h);
        m_lighttex = SDL_CreateTexture(game->get_renderer(), SDL_PIXELTYPE_UNKNOWN, SDL_TEXTUREACCESS_TARGET, game->get_worldsize().w, game->get_worldsize().h);
    }

    ~DrawSystem() {
        SDL_DestroyTexture(m_drawtex);
        SDL_DestroyTexture(m_lighttex);
    }

    void update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt) override {
        // Change to render into rendertexture for now
        SDL_SetRenderTarget(m_game->get_renderer(), m_drawtex);
        SDL_SetRenderDrawColor(m_game->get_renderer(), 0, 100, 200, 255);
        SDL_RenderClear(m_game->get_renderer());

        entityx::ComponentHandle<Drawable> drawable;
        entityx::ComponentHandle<Position> position;
        entityx::ComponentHandle<Controlable> controlable;

        for (entityx::Entity entity : es.entities_with_components(drawable, position)) {
            (void)entity;
            
            SDL_Rect dest;

            dest.x = position->get_position()[0];
            dest.y = position->get_position()[1];
            dest.w = drawable->get_width();
            dest.h = drawable->get_height();
            // std::cout << position->get_position()[0] << std::endl;
            // std::cout << position->get_position()[1] << std::endl;
            // std::cout << drawable->get_width() << std::endl;
            // std::cout << drawable->get_height() << std::endl;

            SDL_RenderCopy(m_game->get_renderer(), m_game->get_res_manager().get_texture(drawable->get_texture_key()),
                           nullptr, &dest);
        }

        SDL_SetRenderDrawColor(m_game->get_renderer(), 255, 100, 200, 255);

        for (entityx::Entity player : es.entities_with_components(controlable, position)) { 
 			(void)player;
	        //SDL_GetMouseState(&x, &y);
	        m_camera.x = position->get_position()[0] - m_camera.w/2;
	        m_camera.y = position->get_position()[1] - m_camera.h/2;

            if (m_camera.x < 0)
                m_camera.x = 0;
            else if (m_camera.x > m_game->get_worldsize().w - m_camera.w)
                m_camera.x = m_game->get_worldsize().w - m_camera.w;

            if (m_camera.y < 0)
                m_camera.y = 0;
            else if (m_camera.y > m_game->get_worldsize().h - m_camera.h)
                m_camera.y = m_game->get_worldsize().h - m_camera.h;


            //std::cout << m_camera.x << " " << m_camera.y << std::endl;
        }

        // Render light map
        SDL_SetRenderTarget(m_game->get_renderer(), m_lighttex);
        SDL_SetRenderDrawColor(m_game->get_renderer(), 0, 0, 0, 255);
        SDL_RenderClear(m_game->get_renderer());
        SDL_SetTextureBlendMode(m_game->get_res_manager().get_texture("gradient"), SDL_BLENDMODE_ADD);
        SDL_Rect lol{50, 50, 100, 100};
        SDL_RenderCopy(m_game->get_renderer(), m_game->get_res_manager().get_texture("gradient"),
                       nullptr, &lol);
        SDL_SetTextureBlendMode(m_lighttex, SDL_BLENDMODE_MOD);
        SDL_SetRenderTarget(m_game->get_renderer(), m_drawtex);
        SDL_RenderCopy(m_game->get_renderer(), m_lighttex, nullptr, nullptr);

        // Render to final window
        SDL_SetRenderTarget(m_game->get_renderer(), nullptr);
        SDL_RenderCopy(m_game->get_renderer(), m_drawtex, &m_camera, nullptr);

        SDL_RenderPresent(m_game->get_renderer());
    }

private:
    Game *m_game;
    SDL_Rect m_camera;
    SDL_Texture *m_drawtex;
    SDL_Texture *m_lighttex;
};
