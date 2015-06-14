#ifndef MOVEMENT_SYSTEM_CPP
#define MOVEMENT_SYSTEM_CPP

#include "events.hpp"
#include "game.hpp"
#include "component_position.hpp"
#include "component_moveable.hpp"
#include "component_player.hpp"

#include "entityx/entityx.h"

#include <glm/vec2.hpp>
#include <type_traits>
#include <iostream>

class MovementSystem : public entityx::System<MovementSystem>, public entityx::Receiver<MovementSystem>  {
public:
    MovementSystem(Game *game) : m_game(game) {}

	void configure(entityx::EventManager &event_manager) {
		event_manager.subscribe<PlayerInstructionEvent>(*this);
	}

	void update(entityx::EntityManager &es, entityx::EventManager &events, double dt) {	
		entityx::ComponentHandle<Moveable> moveable;
		entityx::ComponentHandle<Position> position;

		for(entityx::Entity entity : es.entities_with_components(moveable, position)) {
			(void)entity;
			//std::cout << "velo: " << moveable->get_velocity()[0] <<" "<<  moveable->get_velocity()[1] << std::endl;
			position->set_position(position->get_position() + moveable->get_velocity());
			moveable->set_velocity(moveable->get_velocity() - moveable->get_velocity()  * 0.9f * (float)dt) ;

            // Null speed when we are colliding with an edge
            if (position->get_position().x < 0) {
                moveable->set_velocity({0, moveable->get_velocity().y});
                position->set_position({0, position->get_position().y});
            }

            if (position->get_position().x > m_game->get_worldsize().w - position->get_rect().w) {
                moveable->set_velocity({0, moveable->get_velocity().y});
                position->set_position({m_game->get_worldsize().w - position->get_rect().w,position->get_position().y });
            }

            if (position->get_position().y < 0) {
                moveable->set_velocity({moveable->get_velocity().x, 0});
                position->set_position({position->get_position().x, 0});
            }
            
            if (position->get_position().y > m_game->get_worldsize().h - position->get_rect().h) {
                moveable->set_velocity({moveable->get_velocity().x, 0});
                position->set_position({position->get_position().x, m_game->get_worldsize().h - position->get_rect().h});
            }
        }
    }

	void receive(const PlayerInstructionEvent &player_instruction_event) {
		auto copy = player_instruction_event;
		entityx::ComponentHandle<Moveable> moveable = copy.m_entity.component<Moveable>();
		moveable->accelerate(player_instruction_event.m_direction_vector);
		//std::cout << "moveable" <<moveable->get_velocity().x << moveable->get_velocity().y << std::endl;
	}

private:
    Game *m_game;

};
#endif
