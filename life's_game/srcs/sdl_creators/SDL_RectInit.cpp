#include "life_game.hpp"

SDL_Rect	rect_init(int x, int y, int w, int h)
{
	SDL_Rect	result;

	result.x = x;
	result.y = y;
	result.w = w;
	result.h = h;
	return result;
}

SDL_Rect	*rect_malloc(int x, int y, int w, int h)
{
	SDL_Rect	*result;

	result = new SDL_Rect;
	result->x = x;
	result->y = y;
	result->w = w;
	result->h = h;
	return result;
}

SDL_Rect	*rect_malloc(SDL_Rect pos)
{
	SDL_Rect	*result;

	result = new SDL_Rect;
	result->x = pos.x;
	result->y = pos.y;
	result->w = pos.w;
	result->h = pos.h;
	return result;
}