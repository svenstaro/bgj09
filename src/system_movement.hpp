#ifndef MOVEMENT_SYSTEM_CPP
#define MOVEMENT_SYSTEM_CPP

#include <glm/vec2.hpp>
#include "entityx/entityx.h"
#include "component_position.hpp"
#include "component_moveable.hpp"


class MovementSystem : public entityx::System<MovementSystem>
{
public:
	void update(entityx::EntityManager &es, entityx::EventManager &events, double dt)
	{	
		entityx::ComponentHandle<Moveable> moveable;
		entityx::ComponentHandle<Position> position;
		for(entityx::Entity entity : es.entities_with_components(moveable, position))		
		{
			(void)entity;
		}
	}
};
#endif