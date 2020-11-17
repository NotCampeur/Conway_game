#include "life_game.hpp"

void	event_manager()
{
	SDL_Event			e;

	while (SDL_PollEvent(&e) == 1)
	{
		if (e.type == SDL_QUIT)
			sys->interrupt = SDL_TRUE;
		else if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
			key_manager(e);
		else if (e.type == SDL_KEYDOWN)
			movement_manager(e);
		else if (e.type == SDL_MOUSEBUTTONDOWN && e.button.state == SDL_PRESSED)
			click_manager(e);
		else if (e.type == SDL_MOUSEWHEEL)
			scroll_manager(e);
	}
}