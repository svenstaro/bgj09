#ifndef POSITION_HPP
#define POSITION_HPP

#include "entityx/entityx.h"

#include <glm/vec2.hpp>
struct Position : entityx::Component<Position>
{
	Position(glm::vec2 new_position = glm::vec2(0.0f,0.0f)) : position(new_position){}
	glm::vec2 get_position();
	void set_position(glm::vec2);
private:
	glm::vec2 position;
};

#endif