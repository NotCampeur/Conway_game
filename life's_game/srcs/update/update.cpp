#include "life_game.hpp"

void	update(SDL_Window **win, SDL_Renderer **render)
{
	SDL_bool	interrupt(SDL_FALSE);
	while (interrupt != SDL_TRUE)
	{
		key_manager(*win, &interrupt);
		render_screen(win, render);
	}
}