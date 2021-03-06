#include "entity_creator.hpp"
#include "entityx/entityx.h"
#include "component_player.hpp"
#include "component_moveable.hpp"
#include "component_drawable.hpp"
#include "component_position.hpp"
#include "component_enemy.hpp"
#include "component_light.hpp"
#include <glm/vec2.hpp>
#include <random>

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
	fish.assign<Position>(glm::vec2(500.f,600.f));
	fish.assign<Drawable>("Player",75,75);
	fish.assign<Light>(10,5);
}

void EntityCreator::create_enemy(entityx::EntityManager &entity_manager) {
	entityx::Entity enemy = entity_manager.create();
	enemy.assign<Enemy>();
	enemy.assign<Moveable>(glm::vec2{0.0,0.0},0.1);

	std::random_device random_device;
	std::mt19937 random_engine{random_device()};
	std::uniform_int_distribution<int> die_distribution{1, 6};
	
	int die_roll = die_distribution(random_engine);

	enemy.assign<Position>(glm::vec2{20.f, 100.f * die_roll}, 50, 50);
	enemy.assign<Drawable>("enemy",50,50);
}

void EntityCreator::create_level_1(entityx::EntityManager &entity_manager) {
	entityx::Entity background = entity_manager.create();
	background.assign<Position>();
	background.assign<Drawable>("level_1_bg",1600,1200);
}
