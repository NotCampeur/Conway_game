#include "life_game.hpp"

void	start_window()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		throw std::invalid_argument(E_SDL INIT);
	if (SDL_CreateWindowAndRenderer(800, 800, SDL_WINDOW_SHOWN, &(sys->win), &(sys->render)) < 0)
		throw std::invalid_argument(E_SDL CREATEWINANDRENDERER);
	if (TTF_Init() == -1)
		throw std::invalid_argument(E_SDL FONT);
	if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) == 0)
		throw std::invalid_argument(E_SDL IMAGE_INIT);
	SDL_SetWindowTitle(sys->win, "Life's game of the three tricksters");
}

void	end_program()
{
	if (sys->render != NULL)
		SDL_DestroyRenderer(sys->render);
	if (sys->win != NULL)
		SDL_DestroyWindow(sys->win);
	if (sys->font != NULL)
		TTF_CloseFont(sys->font);
	TTF_Quit();
	SDL_Quit();
	system_delete_grid();
	delete sys;
}

void	system_get_window_size(void)
{
	SDL_GetWindowSize(sys->win, &sys->win_size.x, &sys->win_size.y);
}

void	system_init_grid(void)
{
	std::vector<std::string> proposition(2, "91");

	proposition[1] = "";
	system_delete_grid();
	while (sys->grid_size.x == 0)
		sys->grid_size.x = input_nbr_box("Please enter the width of the grid :", proposition);
	while (sys->grid_size.y == 0)
	{
		proposition[0] = "51";
		sys->grid_size.y = input_nbr_box("Please enter the height of the grid :", proposition);
	}
	sys->grid = new char*[sys->grid_size.y];
	for (int i(0); i < sys->grid_size.y; i++)
		sys->grid[i] = new char[sys->grid_size.x];
	for (int y(0); y < sys->grid_size.y; y++)
		for (int x(0); x < sys->grid_size.x; x++)
			sys->grid[y][x] = '0';
}

void	system_delete_grid(void)
{
	delete [] sys->grid;
}

void	system_init(void)
{
	sys = new t_system;

	sys->win = NULL;
	sys->render = NULL;
	system_get_window_size();
	sys->grid_size = {0, 0};
	sys->grid = NULL;
	sys->gen_count = 0;
	sys->interrupt = SDL_FALSE;
	sys->auto_run = SDL_FALSE;
	sys->fullscreen = SDL_FALSE;
	sys->mouse_left_hold = SDL_FALSE;
	sys->mouse_right_hold = SDL_FALSE;
}
