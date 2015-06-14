#ifndef ENEMY_SYSTEM_CPP
#define ENEMY_SYSTEM_CPP

#include "events.hpp"
#include "component_position.hpp"
#include "component_enemy.hpp"
#include "component_moveable.hpp"
#include "component_controlable.hpp"

#include "entityx/entityx.h"

#include <glm/glm.hpp>
#include <glm/vec2.hpp>
#include <SDL2/SDL.h>
#include <iostream>

class EnemySystem : public entityx::System<EnemySystem> {
public:
	void update(entityx::EntityManager &es, entityx::EventManager &events, double dt) {	
		entityx::ComponentHandle<Position> enemy_position;
		entityx::ComponentHandle<Moveable> enemy_moveable;
		entityx::ComponentHandle<Enemy> enemy_enemy;
		entityx::ComponentHandle<Position> player_position;
		entityx::ComponentHandle<Moveable> player_moveable;
		entityx::ComponentHandle<Controlable> player_controlable;
		for(entityx::Entity enemy : es.entities_with_components(enemy_position, enemy_moveable, enemy_enemy)) {
            for(entityx::Entity player : es.entities_with_components(player_position, player_moveable, player_controlable)) {
                glm::vec2 direction = glm::normalize(player_position->get_position() - enemy_position->get_position());
                enemy_moveable->accelerate(direction);
                (void)enemy;
                (void)player;
            }
        }
    }
};

#endif
