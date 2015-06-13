#include <glm/vec2.hpp>
#include "component_drawable.hpp"
#include "../strapon/resource_manager.hpp"

struct DrawSystem : public entityx::System<DrawSystem>
{
	DrawSystem(Game new_game) : game(new_game)
	void update(entityx::EntityManager &es, entityx::EventManager &events, float dt) override
	{
		ComponentHandle<Draw> draw;
		ComponentHandle<Position> position;
		for (entityx::Entity entity : es.entities_with_components(draw, position))
		{
			renderTexture(resource_manager.get_texture(draw.get_texture_key()),
						  ren,
						  position.get_position()[0],
						  position.get_position()[1],
						  draw.get_width(),
						  draw.get_heigth());
    	}
	}

private:
	Game game;

}