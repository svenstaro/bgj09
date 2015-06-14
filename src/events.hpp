#ifndef EVENTS_HPP
#define EVENTS_HPP

#include "entityx/entityx.h"
#include "glm/glm.hpp"

struct PlayerInstructionEvent {
	PlayerInstructionEvent(glm::vec2 direction_vector, entityx::Entity entity) 
		: m_direction_vector(direction_vector),m_entity(entity){}

	glm::vec2 m_direction_vector;
	entityx::Entity m_entity;
};

struct CollisionEvent {
	CollisionEvent(entityx::Entity first, entityx::Entity second)
		: m_first(first), m_second(second) {}

	entityx::Entity m_first;
	entityx::Entity m_second;
};

#endif
