#include "life_game.hpp"

void	key_manager(SDL_Event e)
{
	if (e.type == SDL_KEYDOWN)
	{
		if (e.key.keysym.sym == SDLK_ESCAPE)
			sys->interrupt = SDL_TRUE;
		else if (e.key.keysym.sym == SDLK_F11)
		{
			if (sys->fullscreen == SDL_TRUE)
			{
				SDL_SetWindowFullscreen(sys->win, 0);
				sys->fullscreen = SDL_FALSE;
			}
			else if (sys->fullscreen == SDL_FALSE)
			{
				SDL_SetWindowFullscreen(sys->win, SDL_WINDOW_FULLSCREEN_DESKTOP);
				sys->fullscreen = SDL_TRUE;
			}
		}
		else if	(e.key.keysym.sym == SDLK_SPACE)
			next_gen();
		else if (e.key.keysym.sym == SDLK_e)
		{
			if (sys->auto_run == SDL_FALSE)
				sys->auto_run = SDL_TRUE;
			else
				sys->auto_run = SDL_FALSE;
		}
		else if (e.key.keysym.sym == SDLK_c)
			clear_grid();
		else if (e.key.keysym.sym == SDLK_r)
			random_grid();
		else if (e.key.keysym.sym == SDLK_s)
			save_grid();
		else if (e.key.keysym.sym == SDLK_l)
			load_grid();
	}
}