#include "life_game.hpp"

void	event_manager(SDL_Window *win, SDL_bool *interrupt)
{
	SDL_Event			e;

	SDL_PollEvent(&e);
	if (e.type == SDL_QUIT)
		*interrupt = SDL_TRUE;
	else if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP)
		key_manager(win, e, interrupt);
	else if (e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP)
		click_manager(e);
	else if (e.type == SDL_MOUSEWHEEL)
		scroll_manager(e);
}