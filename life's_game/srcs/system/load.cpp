#include "life_game.hpp"

int			grid[GRID_HEIGHT][GRID_WIDTH]{};
SDL_bool	auto_run;
SDL_Rect	cam;
int			count_gen;


void	load(SDL_Window **win, SDL_Renderer **render)
{
	count_gen = 0;
	start_window(win, render);
	srand(time(NULL));
	cam = rect_init(0, 0, 1, 1);
	auto_run = SDL_FALSE;
}