#include "life_game.hpp"

void	render_screen(SDL_Window *win, SDL_Renderer *render)
{
	(void)win;
	if (SDL_SetRenderDrawColor(render, 30, 30, 30, 255) != 0)
		throw std::invalid_argument(E_SDL SETRENDERDRAWCOLOR);
	if (SDL_RenderClear(render) != 0)
		throw std::invalid_argument(E_SDL RENDERCLEAR);
	draw_grid(render);
	SDL_RenderPresent(render);
}