#include "life_game.hpp"

static SDL_bool	is_spawnable(int i, int j)
{
	char	neighbours(0);

	if (grid[i][j] == 0)
	{
		for (int n(-1); n < 2; n++)
			for (int m(-1); m < 2; m++)
				if (i + n >= 0 && j + m >= 0 && grid[i + n][j + m] == 1)
					neighbours++;
	}
	if (neighbours == 3)
		return SDL_TRUE;
	return SDL_FALSE;
}

static SDL_bool	is_survivable(int i, int j)
{
	char	neighbours(0);

	if (grid[i][j] == 1)
	{
		for (int n(-1); n < 2; n++)
			for (int m(-1); m < 2; m++)
				if (i + n >= 0 && j + m >= 0 && grid[i + n][j + m] == 1)
					neighbours++;
	}
	if (neighbours == 4 || neighbours == 3)
		return SDL_TRUE;
	return SDL_FALSE;
}

void	next_gen(void)
{
	int	tmp[GRID_WIDTH][GRID_HEIGHT]{};

	for (int i(0); i < GRID_WIDTH; i++)
		for (int j(0); j < GRID_HEIGHT; j++)
			if (is_spawnable(i, j) || is_survivable(i, j))
				tmp[i][j] = 1;
			else
				tmp[i][j] = 0;
	for (int i(0); i < GRID_WIDTH; i++)
		for (int j(0); j < GRID_HEIGHT; j++)
			grid[i][j] = tmp[i][j];
}