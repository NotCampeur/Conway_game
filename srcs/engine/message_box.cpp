#include "life_game.hpp"

void	welcome_message(void)
{
	static bool	printed(false);

	if (printed == false)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "WELCOME",
		"You launch our version of the Conway's game of life \n"
		"                      Have fun\n"
		"    e = auto mode\n"
		"    c = clear\n"
		"    r = random gen\n"
		"    space = next gen\n"
		"    s = save current grid\n"
		"    escape = quit",
		sys->win);
		printed = true;
	}
}