#include "life_game.hpp"

void	start_window()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		throw std::invalid_argument(E_SDL INIT);
	if (SDL_CreateWindowAndRenderer(800, 800, SDL_WINDOW_SHOWN, &(sys->win), &(sys->render)) < 0)
		throw std::invalid_argument(E_SDL CREATEWINANDRENDERER);
	if (TTF_Init() == -1)
		throw std::invalid_argument(E_SDL FONT);
	if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) == 0)
		throw std::invalid_argument(E_SDL IMAGE_INIT);
	SDL_SetWindowTitle(sys->win, "Life's game of the three tricksters");
}

void	end_program()
{
	if (sys->render != NULL)
		SDL_DestroyRenderer(sys->render);
	if (sys->win != NULL)
		SDL_DestroyWindow(sys->win);
	if (sys->font != NULL)
		TTF_CloseFont(sys->font);
	TTF_Quit();
	SDL_Quit();
	delete sys;
}

void	system_get_window_size(void)
{
	SDL_GetWindowSize(sys->win, &sys->win_size.x, &sys->win_size.y);
}

void	system_init(void)
{
	sys = new t_system;

	sys->win = NULL;
	sys->render = NULL;
	sys->gen_count = 0;
	sys->interrupt = SDL_FALSE;
	sys->auto_run = SDL_FALSE;
	sys->fullscreen = SDL_FALSE;
	sys->mouse_left_hold = SDL_FALSE;
	sys->mouse_right_hold = SDL_FALSE;
	sys->cam = rect_init(0, 0, 1, 1);
	system_get_window_size();
}
