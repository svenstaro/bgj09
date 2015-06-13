#ifndef COMPONENT_MOVEABLE_HPP
#define COMPONENT_MOVEABLE_HPP

#include <cmath>
#include <glm/vec2.hpp>
struct Moveable : entityx::Component<Moveable>
{
	Moveable(glm::vec2 new_velo, double new_acc) : m_velocity(new_velo), m_acceleration(new_acc){}
	void set_velocity(glm::vec2 new_velo)
	{
		m_velocity = new_velo;
	}

	void accelerate(glm::vec2 new_velo)
	{
		new_velo *= m_acceleration;
		m_velocity += new_velo;
	}

	glm::vec2 get_velocity()
	{
		return m_velocity;
	}

private:
	glm::vec2 m_velocity;
	double m_acceleration;
};
#endif
