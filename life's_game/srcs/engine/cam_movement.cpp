#include "life_game.hpp"

void	movement_manager(SDL_Event e)
{
		if (e.key.keysym.sym == SDLK_UP)
			sys->cam.y--;
		else if (e.key.keysym.sym == SDLK_LEFT)
			sys->cam.x--;
		else if (e.key.keysym.sym == SDLK_DOWN)
			sys->cam.y++;
		else if	(e.key.keysym.sym == SDLK_RIGHT)
			sys->cam.x++;
}
