#include "life_game.hpp"

SDL_Point	point_init(int x, int y)
{
	SDL_Point	result;

	result.x = x;
	result.y = y;
	return result;
}

SDL_Point	*point_malloc(int x, int y)
{
	SDL_Point	*result;

	result = new SDL_Point;
	result->x = x;
	result->y = y;
	return result;
}

SDL_Point	*point_malloc(SDL_Point pos)
{
	SDL_Point	*result;

	result = new SDL_Point;
	result->x = pos.x;
	result->y = pos.y;
	return result;
}