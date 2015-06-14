#include "entity_creator.hpp"
#include "entityx/entityx.h"
#include "component_controlable.hpp"
#include "component_moveable.hpp"
#include "component_drawable.hpp"
#include "component_position.hpp"
#include <glm/vec2.hpp>


void EntityCreator::create_angler(entityx::EntityManager &entity_manager)
{
	entityx::Entity entity = entity_manager.create();
	entity.assign<Controlable>();
	entity.assign<Moveable>(glm::vec2(0.0,0.0),0.1);
	entity.assign<Position>();
	entity.assign<Drawable>("Player",50,50);
}