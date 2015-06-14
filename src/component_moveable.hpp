#ifndef COMPONENT_MOVEABLE_HPP
#define COMPONENT_MOVEABLE_HPP

#include <cmath>
#include <glm/vec2.hpp>

struct Moveable : entityx::Component<Moveable>
{
	Moveable(glm::vec2 new_velo = glm::vec2(0.0,0.0), double new_acc = 0) : m_velocity(new_velo), m_acceleration(new_acc){}
	void set_velocity(glm::vec2 new_velo)
	{
		m_velocity = new_velo;
	}

	void accelerate(glm::vec2 new_direction)
	{
		new_direction *= m_acceleration;
		m_velocity += new_direction;
	}

	glm::vec2 get_velocity()
	{
		return m_velocity;
	}

	float get_acceleration()
	{
		return m_acceleration;
	}

private:
	glm::vec2 m_velocity;
	double m_acceleration;
};
#endif
