#include "life_game.hpp"

void	movement_manager(SDL_Event e)
{
		if (e.key.keysym.sym == SDLK_UP)
			cam.y--;
		else if (e.key.keysym.sym == SDLK_LEFT)
			cam.x--;
		else if (e.key.keysym.sym == SDLK_DOWN)
			cam.y++;
		else if	(e.key.keysym.sym == SDLK_RIGHT)
			cam.x++;
}
