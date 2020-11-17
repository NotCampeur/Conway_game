#include "life_game.hpp"

void	clear_grid(void)
{
	for (int i(0); i < GRID_HEIGHT; i++)
		for (int j(0); j < GRID_WIDTH; j++)
			sys->grid[i][j] = 0;
}

void	random_grid(void)
{
	for (int i(0); i < GRID_HEIGHT; i++)
		for (int j(0); j < GRID_WIDTH; j++)
			sys->grid[i][j] = rand() % 2;
}

void	save_grid(void)
{
	std::string const	grid_save("ressources/grid_1.txt");
	std::ofstream		flux;
	
	flux.open(grid_save.c_str());
	if (flux)
	{
		for (int y(0); y < GRID_HEIGHT; y++)
		{
			for (int x(0); x < GRID_WIDTH; x++)
				flux << sys->grid[y][x];
			flux << "\n";
		}
	}
	else
		throw std::invalid_argument(" impossible to open the save file");
}