#include "life_game.hpp"

static SDL_bool	is_spawnable(int i, int j)
{
	char	neighbours(0);

	if (sys->grid[i][j] == 0)
	{
		for (int n(-1); n < 2; n++)
			for (int m(-1); m < 2; m++)
				if (i + n >= 0 && j + m >= 0
					&& i + n < GRID_HEIGHT && j + m < GRID_WIDTH
					&& sys->grid[i + n][j + m] == 1)
					neighbours++;
	}
	if (neighbours == 3)
		return SDL_TRUE;
	return SDL_FALSE;
}

static SDL_bool	is_survivable(int i, int j)
{
	char	neighbours(-1);

	if (sys->grid[i][j] == 1)
	{
		for (int n(-1); n < 2; n++)
			for (int m(-1); m < 2; m++)
				if (i + n >= 0 && j + m >= 0
					&& i + n < GRID_HEIGHT && j + m < GRID_WIDTH
					&& sys->grid[i + n][j + m] == 1)
					neighbours++;
	}
	if (neighbours == 3 || neighbours == 2)
		return SDL_TRUE;
	return SDL_FALSE;
}

void	next_gen(void)
{
	sys->gen_count++;
	int	tmp[GRID_HEIGHT][GRID_WIDTH]{};

	for (int i(0); i < GRID_HEIGHT; i++)
		for (int j(0); j < GRID_WIDTH; j++)
			if (is_spawnable(i, j) || is_survivable(i, j))
				tmp[i][j] = 1;
			else
				tmp[i][j] = 0;
	for (int i(0); i < GRID_HEIGHT; i++)
		for (int j(0); j < GRID_WIDTH; j++)
			sys->grid[i][j] = tmp[i][j];
}