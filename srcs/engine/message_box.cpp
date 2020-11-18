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

std::string	input_box(void)
{
	std::string		result("|");
	SDL_Event		e;
	const Uint8		*keystates = SDL_GetKeyboardState(NULL);
	SDL_bool		done(SDL_FALSE);
	SDL_Rect		panel;
	SDL_Rect		text;
	SDL_Rect		answer;
	char			input(0);
	int				win_w(0);
	int				win_h(0);
	unsigned long	index(0);

	SDL_GetWindowSize(sys->win, &win_w, &win_h);
	panel = rect_init(win_w / 2 - 150, win_h /2 - 50, 300, 100);
	text = rect_init(win_w / 2 - 100, win_h /2 - 45, 200, 50);
	while (done == SDL_FALSE)
	{
		while (SDL_PollEvent(&e) == 1)
		{
			answer = rect_init(win_w / 2 - 130, win_h /2 - 5, result.length() * 9, 50);
			if (e.type == SDL_KEYDOWN)
			{
				if (e.key.keysym.sym == SDLK_RETURN && result.size() >= 2)
					done = SDL_TRUE;
				else if ((e.key.keysym.sym >= SDLK_a && e.key.keysym.sym <= SDLK_z)
					|| (e.key.keysym.sym >= SDLK_0 && e.key.keysym.sym <= SDLK_9)
					|| e.key.keysym.sym == SDLK_MINUS)
				{
					input = e.key.keysym.sym;
					if ((keystates[SDL_SCANCODE_RSHIFT] || keystates[SDL_SCANCODE_LSHIFT])
						&& (e.key.keysym.sym >= SDLK_a && e.key.keysym.sym <= SDLK_z))
						input = input - 32;
					if ((keystates[SDL_SCANCODE_RSHIFT] || keystates[SDL_SCANCODE_LSHIFT])
						&& (e.key.keysym.sym == SDLK_MINUS))
						input = '_';
					if ((index + 1) < MAX_SAVE_FILE_NAME)
					{
						result.insert(index, 1, input);
						index++;
					}
				}
				else if (e.key.keysym.sym == SDLK_BACKSPACE)
				{
					if (index > 0)
					{
						result.erase(index - 1, 1);
						index--;
					}
				}
				else if (e.key.keysym.sym == SDLK_DELETE)
				{
					if (index + 1 < result.size())
						result.erase(index + 1, 1);
				}
				else if (e.key.keysym.sym == SDLK_LEFT)
				{
					if (index > 0)
					{
						result[index] = result[index - 1];
						result[index - 1] = '|';
						index--;
					}
				}
				else if (e.key.keysym.sym == SDLK_RIGHT)
				{
					if (index + 1 < result.size())
					{
						result[index] = result[index + 1];
						result[index + 1] = '|';
						index++;
					}
				}
			}
			set_draw_color(30, 30, 200, 255);
			SDL_RenderFillRect(sys->render, &panel);
			draw_pretty_text("Write the file name please :", &text, color_init(0, 0, 0));
			draw_pretty_text(result, &answer, color_init(0, 0, 0));
			SDL_RenderPresent(sys->render);
		}
	}
	result.erase(result.find("|"), 1);
	return result;
}