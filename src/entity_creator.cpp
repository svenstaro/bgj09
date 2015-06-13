#include "entity_creator.hpp"
#include "entityx/entityx.h"
#include "component_controlable.hpp"


EntityCreator::EntityCreator(entityx::EntityManager *entity_manager) : m_entity_manager(entity_manager){}

void EntityCreator::create_angler()
{
	entityx::Entity entity = m_entity_manager->create();
	entity.assign<Controlable>();
}