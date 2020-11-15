#include "life_game.hpp"

int			grid[GRID_WIDTH][GRID_HEIGHT];
SDL_bool	auto_run;

static void	init_grid()
{
	for (int i(0); i < GRID_WIDTH; i++)
		for (int j(0); j < GRID_HEIGHT; j++)
			grid[i][j] = 0;
}

void	load(SDL_Window **win, SDL_Renderer **render)
{
	start_window(win, render);
	init_grid();
	auto_run = SDL_FALSE;
}