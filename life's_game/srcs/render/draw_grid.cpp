#include "life_game.hpp"

void	draw_grid(SDL_Renderer *render)
{
	for (int i(0); i < GRID_WIDTH; i++)
	{
		for (int j(0); j < GRID_HEIGHT; j++)
		{
			if (grid[i][j] == 0)
			{
				SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
				SDL_RenderFillRect(render, rect_malloc(i * 21, j * 21, 20, 20));
			}
			else
			{
				SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
				SDL_RenderFillRect(render, rect_malloc(i * 21, j * 21, 20, 20));
			}
		}
	}
}