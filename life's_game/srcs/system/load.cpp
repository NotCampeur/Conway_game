#include "life_game.hpp"

int			grid[GRID_WIDTH][GRID_HEIGHT]{};
SDL_bool	auto_run;
SDL_Rect	cam;


void	load(SDL_Window **win, SDL_Renderer **render)
{
	start_window(win, render);
	srand(time(NULL));
	cam = rect_init(0, 0, 1, 1);
	auto_run = SDL_FALSE;
}