#include "life_game.hpp"

void	draw_rect(SDL_Rect rect, SDL_Color color)
{
	set_draw_color(color);
	SDL_RenderFillRect(sys->render, &rect);
}
