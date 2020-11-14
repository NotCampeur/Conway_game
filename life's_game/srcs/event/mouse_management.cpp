#include "life_game.hpp"

// This will handle which tile has to be switch according to the cursor position.
// (Need to correct when you click at the bottom of the screen)

void	click_manager(SDL_Event e)
{
	static SDL_bool	click_up(SDL_TRUE);

	if (e.type == SDL_MOUSEBUTTONDOWN && click_up == SDL_TRUE)
	{
		click_up = SDL_FALSE;
		if (grid[e.button.x / 21][e.button.y / 21] == 0)
			grid[e.button.x / 21][e.button.y / 21] = 1;
		else
			grid[e.button.x / 21][e.button.y / 21] = 0;
	}
	else if (e.type == SDL_MOUSEBUTTONUP)
	{
		click_up = SDL_TRUE;
	}
}

void	scroll_manager(SDL_Event e)
{
	(void)e;
	// The zoom will be added later
}