#ifndef COLLISION_SYSTEM_CPP
#define COLLISION_SYSTEM_CPP

#include "events.hpp"
#include "component_position.hpp"
#include "component_player.hpp"
#include "component_enemy.hpp"

#include "entityx/entityx.h"
#include "game.hpp"

#include <glm/vec2.hpp>
#include <SDL2/SDL.h>
#include <iostream>

class CollisionSystem : public entityx::System<CollisionSystem> {
public:
    CollisionSystem(Game *game) : m_game(game){}

	void update(entityx::EntityManager &es, entityx::EventManager &events, double dt) {	
		entityx::ComponentHandle<Position> first_position, second_position;
		for(entityx::Entity first_entity : es.entities_with_components(first_position)) {
            for(entityx::Entity second_entity : es.entities_with_components(second_position)) {
                if (first_entity != second_entity &&
                        SDL_HasIntersection(&first_position->get_rect(), &second_position->get_rect())) {
                    // events.emit<CollisionEvent>(first_entity, second_entity);

                    entityx::ComponentHandle<Player> player;
                    if(first_entity.has_component<Player>())
                        player = first_entity.component<Player>();
                    else if(second_entity.has_component<Player>())
                        player = second_entity.component<Player>();

                    player->set_lives(player->get_lives() - 1);
                    if(player->get_lives() <= 0)
                    {
                        m_game->gameover();
                    }

                        //if(enemy)
                }
            }
        }
    }
    private:
    Game *m_game;
};

#endif
