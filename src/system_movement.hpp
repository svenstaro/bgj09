#ifndef MOVEMENT_SYSTEM_CPP
#define MOVEMENT_SYSTEM_CPP

#include "events.hpp"
#include "component_position.hpp"
#include "component_moveable.hpp"
#include "component_controlable.hpp"

#include "entityx/entityx.h"

#include <glm/vec2.hpp>
#include <type_traits>
#include <iostream>

class MovementSystem : public entityx::System<MovementSystem>, public entityx::Receiver<MovementSystem> 
{
public:
	void configure(entityx::EventManager &event_manager)
	{
		event_manager.subscribe<PlayerInstructionEvent>(*this);
	}
	void update(entityx::EntityManager &es, entityx::EventManager &events, double dt)
	{	
		entityx::ComponentHandle<Moveable> moveable;
		entityx::ComponentHandle<Position> position;
		for(entityx::Entity entity : es.entities_with_components(moveable, position))		
		{
			(void)entity;
			//std::cout << "velo: " << moveable->get_velocity()[0] <<" "<<  moveable->get_velocity()[1] << std::endl;
			position->set_position(position->get_position() + moveable->get_velocity());
			moveable->set_velocity(moveable->get_velocity() - moveable->get_velocity()  * 0.9f * (float)dt) ;
		}
	}
	void receive(const PlayerInstructionEvent &player_instruction_event)
	{
		auto copy = player_instruction_event;
		entityx::ComponentHandle<Moveable> moveable = copy.m_entity.component<Moveable>();
		moveable->accelerate(player_instruction_event.m_direction_vector);
		//std::cout << "moveable" <<moveable->get_velocity().x << moveable->get_velocity().y << std::endl;
	}
};
#endif
