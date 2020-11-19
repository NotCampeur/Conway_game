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
	std::ofstream				flux;
	std::string					file_name;
	SDL_bool					confirm(SDL_FALSE);
	std::vector<std::string>	proposition(1, "grid_number_");

	file_name = input_box("Write the file name please :", proposition);
	confirm = confirm_message("Please confirm", "Do you want to save the grid as : " + file_name);
	if (confirm == SDL_TRUE)
	{
		flux.open("ressources/grid/" + file_name);
		if (flux)
			for (int y(0); y < GRID_HEIGHT; y++)
			{
				for (int x(0); x < GRID_WIDTH; x++)
				{
					flux << sys->grid[y][x];
					flux << ' ';
				}
				flux << "\n";
			}
		else
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, "CAREFUL"
									, "The file can't be created / overwrite", sys->win);
	}
	flux.close();
}

static std::vector<std::string> grid_load_list()
{
	std::ifstream				flux("ressources/saved_grid.txt");
	unsigned int				file_nb(0);
	std::vector<std::string>	file_names;

	system_get_window_size();
	system("ls ressources/grid | wc -l > ressources/saved_grid.txt && ls ressources/grid >> ressources/saved_grid.txt");
	flux >> file_nb;
	file_names.resize(file_nb);
	for (unsigned int i(0); i < file_nb; i++)
		flux >> file_names[i];
	draw_rect(rect_init(sys->win_size.x / 2 - 150, sys->win_size.y /2 - 100 - (file_nb * 50), 300, 50 + (file_nb * 50)), color_init(10, 70, 160));
	draw_pretty_text("The saved grids : ", rect_init(sys->win_size.x / 2 - 100, sys->win_size.y /2 - 95 - (file_nb * 50), 200, 50), color_init(0, 0, 0));
	for (unsigned long i(0); i < file_names.size(); i++)
		draw_pretty_text(file_names[i], rect_init(sys->win_size.x / 2 - 135, sys->win_size.y /2 - 45 - (file_nb * 50) + (i * 50), file_names[i].length() * 9, 50), color_init(0, 0, 0));
	SDL_RenderPresent(sys->render);
	return file_names;
}

void	load_grid(void)
{
	std::ifstream				flux;
	std::string					file_name;
	SDL_bool					confirm(SDL_FALSE);
	std::vector<std::string>	file_list;

	file_list = grid_load_list();
	file_name = input_box("Which one do you want to load :", file_list);
	confirm = confirm_message("Please confirm", "Do you want to load : " + file_name);
	if (confirm == SDL_TRUE)
	{
		flux.open("ressources/grid/" + file_name);
		if (flux)
			for (int y(0); y < GRID_HEIGHT; y++)
				for (int x(0); x < GRID_WIDTH; x++)
					flux >> sys->grid[y][x];
		else
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, "CAREFUL"
									, "The file can't be open", sys->win);
	}
	flux.close();
}