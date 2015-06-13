#ifndef POSITION_HPP
#define POSITION_HPP

#include "entityx/entityx.h"

#include <glm/vec2.hpp>
struct Position : entityx::Component<Position>
{
	Position(glm::vec2 new_position = glm::vec2(0.0f,0.0f)) : m_position(new_position){}
	glm::vec2 get_position()
	{
		return m_position;
	}
	void set_position(glm::vec2 new_position)
	{
		m_position = new_position;
	}

private:
	glm::vec2 m_position;
};

#endif