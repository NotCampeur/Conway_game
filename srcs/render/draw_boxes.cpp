#include "life_game.hpp"

void	draw_load_list(std::vector<std::string>	file_names)
{
	size_t	file_nb(0);

	file_nb = file_names.size();
	draw_rect(rect_init(sys->win_size.x / 2 - 150, sys->win_size.y /2 - 100 - (file_nb * 50), 300, 50 + (file_nb * 50)), color_init(10, 70, 160));
	draw_pretty_text("The saved grids : ", rect_init(sys->win_size.x / 2 - 100, sys->win_size.y /2 - 95 - (file_nb * 50), 200, 50), color_init(0, 0, 0));
	for (unsigned long i(0); i < file_nb; i++)
		draw_pretty_text(file_names[i], rect_init(sys->win_size.x / 2 - 135, sys->win_size.y /2 - 50 - (file_nb * 50) + (i * 50), file_names[i].length() * 9, 50), color_init(0, 0, 0));
	SDL_RenderPresent(sys->render);
}