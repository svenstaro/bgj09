#include "entity_creator.hpp"
#include "entityx/entityx.h"
#include "component_player.hpp"
#include "component_moveable.hpp"
#include "component_drawable.hpp"
#include "component_position.hpp"
#include "component_enemy.hpp"
#include "component_light.hpp"
#include <glm/vec2.hpp>


// void EntityCreator::create_obstacle(entityx::EntityManager &entity_manager) {
// 	entityx::Entity entity = entity_manager.create();
// 	entity.assign<Player>();
// 	entity.assign<Moveable>(glm::vec2(0.0, 0.0), 0.1);
// 	entity.assign<Position>();
// 	entity.assign<Drawable>("Obstacle", 50, 50);
// }

void EntityCreator::create_angler(entityx::EntityManager &entity_manager) {
	entityx::Entity fish = entity_manager.create();
	fish.assign<Player>(2, 100);
	fish.assign<Moveable>(glm::vec2(0.0,0.0),0.1);
	fish.assign<Position>();
	fish.assign<Drawable>("Player",75,75);
	fish.assign<Light>(10,5);
}

void EntityCreator::create_enemy(entityx::EntityManager &entity_manager) {
	entityx::Entity enemy = entity_manager.create();
	enemy.assign<Enemy>();
	enemy.assign<Moveable>(glm::vec2{0.0,0.0},0.1);
	enemy.assign<Position>(glm::vec2{100.f, 100.f}, 50, 50);
	enemy.assign<Drawable>("enemy",50,50);
}

void EntityCreator::create_level_1(entityx::EntityManager &entity_manager) {
	entityx::Entity background = entity_manager.create();
	background.assign<Position>();
	background.assign<Drawable>("level_1_bg",1600,1200);
}
