#include "life_game.hpp"

void	start_window(SDL_Window **win, SDL_Renderer **render)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		throw std::invalid_argument(E_SDL INIT);
	if (SDL_CreateWindowAndRenderer(800, 800, SDL_WINDOW_SHOWN, win, render) < 0)
		throw std::invalid_argument(E_SDL CREATEWINANDRENDERER);
}

void	end_program(SDL_Window *win, SDL_Renderer *render)
{
	if (render != NULL)
		SDL_DestroyRenderer(render);
	if (win != NULL)
		SDL_DestroyWindow(win);
	SDL_Quit();
}