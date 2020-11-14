#include "life_game.hpp"

void	key_manager(SDL_Window *win, SDL_Event e, SDL_bool *interrupt)
{
	static	SDL_bool	fullscreen(SDL_FALSE);
	static	SDL_bool	is_f11_up(SDL_TRUE);

	if (e.type == SDL_KEYDOWN)
	{
		if (e.key.keysym.sym == SDLK_ESCAPE)
			*interrupt = SDL_TRUE;
		else if (e.key.keysym.sym == SDLK_F11 && is_f11_up == SDL_TRUE)
		{
			is_f11_up = SDL_FALSE;
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
	}
	if (e.type == SDL_KEYUP)
		if (e.key.keysym.sym == SDLK_F11)
			is_f11_up = SDL_TRUE;
}