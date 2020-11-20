#include "life_game.hpp"

static SDL_bool	is_spawnable(int i, int j)
{
	char	neighbours(0);
	int		y(i);
	int		x(j);

	if (sys->grid[i][j] == '0')
	{
		for (int n(-1); n < 2; n++)
		{
			i = y;
			for (int m(-1); m < 2; m++)
			{
				j = x;
				if (i + n < 0)
					i = sys->grid_size.y;
				else if (i + n >= sys->grid_size.y)
					i = -1;
				if (j + m < 0)
					j = sys->grid_size.x;
				else if (j + m >= sys->grid_size.x)
					j = -1;
				if (sys->grid[i + n][j + m] == '1')
					neighbours++;
			}
		}
	}
	if (neighbours == 3)
		return SDL_TRUE;
	return SDL_FALSE;
}

static SDL_bool	is_survivable(int i, int j)
{
	char	neighbours(-1);
	int		y(i);
	int		x(j);

	if (sys->grid[i][j] == '1')
	{
		for (int n(-1); n < 2; n++)
		{
			i = y;
			for (int m(-1); m < 2; m++)
			{
				j = x;
				if (i + n < 0)
					i = sys->grid_size.y;
				else if (i + n >= sys->grid_size.y)
					i = -1;
				if (j + m < 0)
					j = sys->grid_size.x;
				else if (j + m >= sys->grid_size.x)
					j = -1;
				if (sys->grid[i + n][j + m] == '1')
					neighbours++;
			}
		}
	}
	if (neighbours == 3 || neighbours == 2)
		return SDL_TRUE;
	return SDL_FALSE;
}

void	next_gen(void)
{
	char	tmp[sys->grid_size.y][sys->grid_size.x];

	sys->gen_count++;
	for (int i(0); i < sys->grid_size.y; i++)
		for (int j(0); j < sys->grid_size.x; j++)
			if (is_spawnable(i, j) == SDL_TRUE || is_survivable(i, j) == SDL_TRUE)
				tmp[i][j] = '1';
			else
				tmp[i][j] = '0';
	for (int i(0); i < sys->grid_size.y; i++)
		for (int j(0); j < sys->grid_size.x; j++)
			sys->grid[i][j] = tmp[i][j];
}