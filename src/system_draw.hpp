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
	DrawSystem(Game *new_game) : m_game(new_game){}
	void update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt) override
	{
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
						   m_game->get_res_manager()->get_texture(drawable->get_texture_key()),
						   NULL,
						   &dest);
    	}
	}
private:
	Game *m_game;
};