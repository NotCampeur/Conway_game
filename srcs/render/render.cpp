#include "life_game.hpp"

void	render_texture(SDL_Texture **tex, SDL_Rect *src, SDL_Rect *dst, bool horizontal_flip)
{
	if (horizontal_flip == true)
	{
		if (SDL_RenderCopyEx(sys->render, *tex, src, dst, 0, NULL, SDL_RendererFlip(SDL_FLIP_HORIZONTAL)) == -1)
			throw std::invalid_argument(E_SDL RENDER_COPY_EX);
	}
	else
	{
		if (SDL_RenderCopy(sys->render, *tex, src, dst) == -1)
			throw std::invalid_argument(E_SDL RENDER_COPY);
	}
}

void	render_screen()
{
	set_draw_color(30, 30, 30, 255);
	if (SDL_RenderClear(sys->render) != 0)
		throw std::invalid_argument(E_SDL RENDERCLEAR);
	draw_grid();
	draw_text(std::to_string(sys->gen_count)
			, rect_init(10, 10, std::to_string(sys->gen_count).length() * 14, 50)
			, color_init(255, 0, 0));
	SDL_RenderPresent(sys->render);
	welcome_message();
}