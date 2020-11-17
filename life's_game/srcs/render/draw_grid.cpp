#include "life_game.hpp"

void	draw_grid(SDL_Renderer *render)
{
	SDL_Rect	square;

	for (int i(0); i < GRID_HEIGHT; i++)
	{
		for (int j(0); j < GRID_WIDTH; j++)
		{
			if (grid[i][j] == 0)
				SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
			else
				if (auto_run == SDL_FALSE)
					SDL_SetRenderDrawColor(render, 200, 200, 200, 255);
				else
					SDL_SetRenderDrawColor(render, 0, 125, 225, 255);
			square = rect_init(j * (TILE_HEIGHT + 1), i * (TILE_WIDTH + 1), TILE_WIDTH, TILE_HEIGHT);
			SDL_RenderFillRect(render, &square);
		}
	}
}