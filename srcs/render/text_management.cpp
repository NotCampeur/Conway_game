#include "life_game.hpp"

void	draw_text(std::string to_print, SDL_Rect *pos, SDL_Color color)
{
	render_texture(create_texture(TTF_RenderText_Solid(sys->font, to_print.c_str(), color)), NULL, pos);
}

void	draw_pretty_text(std::string to_print, SDL_Rect *pos, SDL_Color color)
{
	render_texture(create_texture(TTF_RenderText_Blended(sys->font, to_print.c_str(), color)), NULL, pos);
}