#include "game.hpp"
#include "component_drawable.hpp"
#include "component_position.hpp"

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
    }

	void update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt) override
	{
        SDL_SetRenderDrawColor(m_game->get_renderer(), 0, 100, 200, 255);
        SDL_RenderClear(m_game->get_renderer());

		entityx::ComponentHandle<Drawable> drawable;
		entityx::ComponentHandle<Position> position;
		for (entityx::Entity entity : es.entities_with_components(drawable, position))
		{
			(void)entity;
			SDL_Rect dest;
			dest.x = position->get_position()[0];
			dest.y = position->get_position()[1];
			dest.w = drawable->get_width();
			dest.h = drawable->get_height();
			SDL_RenderCopy(m_game->get_renderer(),
						   m_game->get_res_manager().get_texture(drawable->get_texture_key()),
						   NULL,
						   &dest);
    	}

        SDL_SetRenderDrawColor(m_game->get_renderer(), 255, 100, 200, 255);
        SDL_Rect rect{0, 0, 400, 400};
        SDL_RenderFillRect(m_game->get_renderer(), &rect);
        SDL_RenderPresent(m_game->get_renderer());
	}

private:
	Game *m_game;
    SDL_Rect m_camera;
};
