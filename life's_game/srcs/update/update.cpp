#include "life_game.hpp"

void	update(SDL_Window *win, SDL_Renderer *render)
{
	SDL_bool	interrupt(SDL_FALSE);

	while (interrupt != SDL_TRUE)
	{
		event_manager(win, &interrupt);
		if (auto_run == SDL_TRUE)
			next_gen();
		render_screen(win, render);
	}
}