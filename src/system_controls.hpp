#ifndef SYSTEM_CONTROLS_HPP
#define SYSTEM_CONTROLS_HPP
	
#include "events.hpp"
#include "component_player.hpp"
#include <glm/vec2.hpp>
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <iostream>


class ControlSystem : public entityx::System<ControlSystem>
{
public:
	void update(entityx::EntityManager &es, entityx::EventManager &events, double dt)
	{
		entityx::ComponentHandle<Moveable> moveable;
		entityx::ComponentHandle<Position> position;
		entityx::ComponentHandle<Player> player;

		for(entityx::Entity entity : es.entities_with_components(player))
		{
			float x = 0.0f;
			float y = 0.0f;

			const Uint8 *state = SDL_GetKeyboardState(NULL);
			if(state[SDL_SCANCODE_W])
			{
				y-=1.0f;
			}
			if(state[SDL_SCANCODE_A])
			{
				x-=1.0f;
			}
			if(state[SDL_SCANCODE_S])
			{
				y+=1.0f;
			}
			if(state[SDL_SCANCODE_D])
			{
				x+=1.0f;
			}
			if(state[SDL_SCANCODE_SPACE])
			{
				events.emit<PlayerInstructionLight>(entity);
			}
			if(x != 0.0f || y != 0.0f)
			{
				glm::vec2 direction(x,y);
				direction = glm::normalize(direction);// *(float) dt;
				events.emit<PlayerInstructionEvent>(direction,entity);
			}
			
		}
	}
};
#endif