#include "life_game.hpp"

void	update(SDL_Window *win, SDL_Renderer *render)
{
	SDL_bool	interrupt(SDL_FALSE);
	Uint32		act_t(0);
	Uint32		prev_t(0);

	while (interrupt == SDL_FALSE)
	{
		event_manager(win, &interrupt);
		act_t = SDL_GetTicks();
		if (act_t - prev_t >= 100)
		{
			if (auto_run == SDL_TRUE)
				next_gen();
			prev_t = act_t;
		}
		render_screen(win, render);
	}
}