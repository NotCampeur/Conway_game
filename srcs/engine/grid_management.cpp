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
	std::ofstream		flux;
	std::string			file_name;
	SDL_bool			confirm(SDL_FALSE);

	file_name = input_box("Write the file name please :");
	confirm = confirm_message("Please confirm", "Do you want to save the grid as : " + file_name);
	if (confirm == SDL_TRUE)
	{
		flux.open("ressources/grid/" + file_name);
		if (flux)
			for (int y(0); y < GRID_HEIGHT; y++)
			{
				for (int x(0); x < GRID_WIDTH; x++)
					flux << sys->grid[y][x];
				flux << "\n";
			}
		else
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, "CAREFUL"
									, "The file can't be created / overwrite", sys->win);
	}
}