#ifndef DRAW_HPP
#define DRAW_HPP

#include "entityx/entityx.h"

#include <SDL2/SDL.h>

struct Draw : entityx::Component<Draw>
{
	Draw(Texture *new_texture) : texture(new_texture)
	{
		crop_ = SDL_Rect{ 0, 0, 0, 0 };
	};

	SDL_Texture *texture;
	SDL_Rect rect;
};
#endif