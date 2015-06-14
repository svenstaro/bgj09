#include "entity_creator.hpp"
#include "entityx/entityx.h"
#include "component_controlable.hpp"
#include "component_moveable.hpp"
#include "component_drawable.hpp"
#include "component_position.hpp"
#include <glm/vec2.hpp>


void EntityCreator::create_angler(entityx::EntityManager &entity_manager)
{
	entityx::Entity fish = entity_manager.create();
	fish.assign<Controlable>();
	fish.assign<Moveable>(glm::vec2(0.0,0.0),0.1);
	fish.assign<Position>();
	fish.assign<Drawable>("Player",50,50);
	fiss.assign<Light>(10);
}

void EntityCreator::create_level_1(entityx::EntityManager &entity_manager)
{
	entityx::Entity background = entity_manager.create();
	background.assign<Position>();
	background.assign<Drawable>("level_1_bg",1600,1200);
}