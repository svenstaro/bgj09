#ifndef COMPONENT_PLAYER_HPP
#define COMPONENT_PLAYER_HPP

#include "entityx/entityx.h"
#include <SDL2/SDL.h>


struct Player : entityx::Component<Player>
{
	Player(int lives, float light_energy) : m_lives(lives), m_light_energy(light_energy){}
	
	int get_lives()
	{
		return m_lives;
	}
	
	void set_lives(int new_count)
	{
		m_lives = new_count;
	}

	float get_light_energy()
	{
		return m_light_energy;
	}
	void set_light_energy(float light_energy)
	{
		m_light_energy = light_energy;
	}

private:	
	int m_lives;
	float m_light_energy;
};
#endif
