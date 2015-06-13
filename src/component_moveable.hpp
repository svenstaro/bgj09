#ifndef COMPONENT_MOVEABLE_HPP
#define COMPONENT_MOVEABLE_HPP

#include <cmath>
#include <glm/vec2.hpp>
struct Moveable : entityx::Component<Moveable>
{
	Moveable(glm::vec2 new_velo) : m_velocity(new_velo){}
	void set_velocity(glm::vec2 new_velo)
	{
		m_velocity = new_velo;
	}

	glm::vec2 get_velocity()
	{
		return m_velocity;
	}

	float get_absolute_speed()
	{
		//return glm::lengthgit (m_velocity));
		return 0.0f;
	}

private:
	glm::vec2 m_velocity;
};
#endif
