#include "life_game.hpp"

void	draw_grid()
{
	SDL_Rect	square;

	for (int i(0); i < GRID_WIDTH; i++)
	{
		for (int j(0); j < GRID_HEIGHT; j++)
		{
			if (sys->grid[i][j] == 0)
				SDL_SetRenderDrawColor(sys->render, 255, 255, 255, 255);
			else
				if (sys->auto_run == SDL_FALSE)
					SDL_SetRenderDrawColor(sys->render, 0, 0, 0, 255);
				else
					SDL_SetRenderDrawColor(sys->render, 0, 125, 225, 255);
			square = rect_init(i * (TILE_WIDTH + 1), j * (TILE_HEIGHT + 1), TILE_WIDTH, TILE_HEIGHT);
			SDL_RenderFillRect(sys->render, &square);
		}
	}
}