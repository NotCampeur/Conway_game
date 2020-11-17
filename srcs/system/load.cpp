#include "life_game.hpp"

t_system *sys = NULL;

void	load()
{
	system_malloc();
	start_window();
	srand(time(NULL));
}