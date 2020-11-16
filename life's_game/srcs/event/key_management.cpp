#include "life_game.hpp"

void	key_manager(SDL_Window *win, SDL_Event e, SDL_bool *interrupt)
{
	static	SDL_bool	fullscreen(SDL_FALSE);

	if (e.type == SDL_KEYDOWN)
	{
		if (e.key.keysym.sym == SDLK_ESCAPE)
			*interrupt = SDL_TRUE;
		else if (e.key.keysym.sym == SDLK_F11)
		{
			if (fullscreen == SDL_TRUE)
			{
				SDL_SetWindowFullscreen(win, 0);
				fullscreen = SDL_FALSE;
			}
			else if (fullscreen == SDL_FALSE)
			{
				SDL_SetWindowFullscreen(win, SDL_WINDOW_FULLSCREEN_DESKTOP);
				fullscreen = SDL_TRUE;
			}
		}
		else if	(e.key.keysym.sym == SDLK_SPACE)
			next_gen();
		else if (e.key.keysym.sym == SDLK_e)
			auto_run = SDL_TRUE;
		else if (e.key.keysym.sym == SDLK_d)
			auto_run = SDL_FALSE;
		else if (e.key.keysym.sym == SDLK_c)
			clear_grid();
		else if (e.key.keysym.sym == SDLK_r)
			random_grid();
	}
}