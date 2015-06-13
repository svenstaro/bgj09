#ifndef DRAW_HPP
#define DRAW_HPP

#include "entityx/entityx.h"

#include <SDL2/SDL.h>

struct Drawable : entityx::Component<Drawable>
{
	Drawable(std::string key, float new_height, float new_width)
		: texture_map_key(key), height(new_height), width(new_width){}

	float get_height()
	{
		return height;
	}
	float get_width() 
	{
		return width;
	}
	void set_hight(float new_height) 
	{
		height = new_height;
	}
	void set_width(float new_width) 
	{
		width = new_width;
	}
	std::string get_texture_key() 
	{
		return texture_map_key;
	}
private:
	std::string texture_map_key;
	float height;
	float width;
};
#endif