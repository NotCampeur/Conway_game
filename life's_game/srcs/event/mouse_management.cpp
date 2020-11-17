#include "life_game.hpp"

// This will handle which tile has to be switch according to the cursor position.
// (Need to correct when you click at the bottom of the screen)

void	click_manager(SDL_Event e)
{
	if (e.type == SDL_MOUSEBUTTONDOWN
		&& e.button.y < (TILE_HEIGHT + 1) * GRID_HEIGHT
		&& e.button.x < (TILE_WIDTH + 1) * GRID_WIDTH)
	{
		if (grid[e.button.y / (TILE_HEIGHT + 1)][e.button.x / (TILE_WIDTH + 1)] == 0)
			grid[e.button.y / (TILE_HEIGHT + 1)][e.button.x / (TILE_WIDTH + 1)] = 1;
		else
			grid[e.button.y / (TILE_HEIGHT + 1)][e.button.x / (TILE_WIDTH + 1)] = 0;
	}
}

void	scroll_manager(SDL_Event e)
{
	(void)e;
	// The zoom will be added later
}