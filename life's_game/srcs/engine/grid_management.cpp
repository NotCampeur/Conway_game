#include "life_game.hpp"

void	clear_grid(void)
{
	for (int i(0); i < GRID_WIDTH; i++)
		for (int j(0); j < GRID_HEIGHT; j++)
			sys->grid[i][j] = 0;
}

void	random_grid(void)
{
	for (int i(0); i < GRID_WIDTH; i++)
		for (int j(0); j < GRID_HEIGHT; j++)
			sys->grid[i][j] = rand() % 2;
}