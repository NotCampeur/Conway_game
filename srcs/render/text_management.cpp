#include "life_game.hpp"

void	draw_text(const char *to_print, SDL_Rect *pos, SDL_Color color)
{
	render_texture(create_texture(TTF_RenderText_Solid(sys->font, to_print, color)), NULL, pos);
}