#include "life_game.hpp"

SDL_Color	color_init(Uint8 r, Uint8 g, Uint8 b)
{
	SDL_Color	result;

	result.r = r;
	result.g = g;
	result.b = b;
	return result;
}

SDL_Color	*color_malloc(Uint8 r, Uint8 g, Uint8 b)
{
	SDL_Color	*result;

	result = new SDL_Color;
	result->r = r;
	result->g = g;
	result->b = b;
	return result;
}

SDL_Color	*color_malloc(SDL_Color color)
{
	SDL_Color	*result;

	result = new SDL_Color;
	result->r = color.r;
	result->g = color.g;
	result->b = color.b;
	return result;
}

void		SDL_SetRenderDrawColor(SDL_Renderer *render, SDL_Color color)
{
	SDL_SetRenderDrawColor(render, color.r, color.g, color.b, 255);
}