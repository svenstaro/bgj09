#ifndef EVENTS_HPP
#define EVENTS_HPP

struct PlayerInstructionEvent
{
	PlayerInstructionEvent(glm::vec2 direction_vector, entityx::Entity entity) 
		: m_direction_vector(direction_vector),m_entity(entity){}

	glm::vec2 m_direction_vector;
	entityx::Entity m_entity;
};

#endif