#include "life_game.hpp"

t_system *sys = NULL;

void	load()
{
	system_init();
	start_window();
	sys->font = TTF_OpenFont("ressources/fonts/OpenSans-Bold.ttf", 20);
	system_init_grid();
	srand(time(NULL));
}
