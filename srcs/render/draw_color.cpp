#include "life_game.hpp"

void	set_draw_color(SDL_Color color)
{
	if (SDL_SetRenderDrawColor(sys->render, color.r, color.g, color.b, 255) != 0)
		throw std::invalid_argument(E_SDL SETRENDERDRAWCOLOR);
}

void	set_draw_color(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	if (SDL_SetRenderDrawColor(sys->render, r, g, b, a) != 0)
		throw std::invalid_argument(E_SDL SETRENDERDRAWCOLOR);
}
