#ifndef POSITION_HPP
#define POSITION_HPP
//#include TODO entityx includen
#include <glm/vec2.hpp>
struct Position : entity::Component<Position>
{
	glm::vec2<float> get_position();
	void set_position(glm::vec2<float>);
private:
	glm::vec2<float>;
};

#endif