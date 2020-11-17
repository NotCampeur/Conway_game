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
	SDL_Rect	pos;

	if (SDL_SetRenderDrawColor(sys->render, 30, 30, 30, 255) != 0)
		throw std::invalid_argument(E_SDL SETRENDERDRAWCOLOR);
	if (SDL_RenderClear(sys->render) != 0)
		throw std::invalid_argument(E_SDL RENDERCLEAR);
	draw_grid();
	pos = rect_init(500, 200, 300, 300);
	render_texture(create_image_texture("ressources/ncoudsi.jpg"), NULL, &pos);
	pos = rect_init(500, 500, 300, 50);
	//draw_text("Un pure BG, il est trop craquant", &pos, color_init(0, 0, 0));
	SDL_RenderPresent(sys->render);
}