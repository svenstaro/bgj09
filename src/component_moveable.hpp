#ifndef COMPONENT_MOVABLE_HPP
#define COMPONENT_MOVABLE_HPP

#include <cmath>
#include <glm/vec2.hpp>
struct Movable
{
	Movable(glm::vec2 new_velo = {0,0}) : velocity(new_velo){}
	void set_velocity(glm::vec2 new_velo)
	{
		velocity = new_velo;
	}

	glm::vec2 get_velocity()
	{
		return velocity;
	}

	float get_absolute_speed()
	{
		return glm::length(velocity));
	}

private:
	glm::vec2 velocity;
};
#endif
