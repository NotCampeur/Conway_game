#include "life_game.hpp"

void	update()
{
	Uint32		act_t(0);
	Uint32		prev_t(0);

	while (sys->interrupt == SDL_FALSE)
	{
		act_t = SDL_GetTicks();
		event_manager();
		if (act_t - prev_t >= 0)
		{
			if (sys->auto_run == SDL_TRUE)
				next_gen();
			prev_t = act_t;
		}
		render_screen();
	}
}