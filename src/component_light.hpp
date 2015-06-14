#ifndef COMPONENT_LIGHT_HPP
#define COMPONENT_LIGHT_HPP

struct Light : entityx::Component<Interactable>
{
	Light(double radius) : m_radius(radius){}
	
	double get_radius()
	{
		return m_radius;
	};
	void set_radius(double radius)
	{
		m_radius = radius;
	};
private:
	double m_radius;
};
	
#endif