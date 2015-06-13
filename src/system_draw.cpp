#include <glm/vec2>
#include "component_draw.hpp"
#include "strapon/resource_manager.hpp"

struct DrawSystem : public System<DrawSystem>
{
	DrawSystem(ResourceManager *new_res_man, SDL_Renderer *new_ren) : resource_manager(new_res_man), ren(new_ren)
	void update(entityx::EntityManager &es, entityx::EventManager &events, TimeDelta dt) override
	{
		ComponentHandle<Draw> draw;
		ComponentHandle<Position> position;
		for (Entity entity : es.entities_with_components(draw))
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
	ResourceManager *resource_manager;
	SDL_Renderer *ren;

}