#ifndef ENTITY_CREATOR_HPP
#define ENTITY_CREATOR_HPP

#include "entityx/entityx.h"

class EntityCreator
{
public:
	EntityCreator(entityx::EntityManager *entity_manager);
	
	void create_angler();
private:
	entityx::EntityManager *m_entity_manager;
};

#endif