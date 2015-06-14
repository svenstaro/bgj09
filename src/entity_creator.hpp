#ifndef ENTITY_CREATOR_HPP
#define ENTITY_CREATOR_HPP

#include "entityx/entityx.h"

class EntityCreator
{
public:
	static void create_angler(entityx::EntityManager &entity_manager);
	static void create_obstacle(entityx::EntityManager &entity_manager);
};

#endif
