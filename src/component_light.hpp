#ifndef COMPONENT_LIGHT_HPP
#define COMPONENT_LIGHT_HPP

struct Light : entityx::Component<Light>
{
	Light(double radius, double light_decay) : m_radius(radius),m_light_decay(light_decay){}

	double get_radius()
	{
		return m_radius;
	};
	void set_radius(double radius)
	{
		m_radius = radius;
	};

	double get_light_decay()
	{
		return m_light_decay;
	};
private:
	double m_radius;
	double m_light_decay;
};
	
#endif