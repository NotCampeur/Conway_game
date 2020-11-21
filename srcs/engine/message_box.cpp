#include "life_game.hpp"

void	welcome_message(void)
{
	static bool	printed(false);

	if (printed == false)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "WELCOME",
		"You launch our version of the Conway's game of life \n"
		"                      Have fun\n"
		"  e = auto mode                   space = next gen\n"
		"  c = clear                         r = random gen\n"
		"  l_click = spawn cells    r_click = destroy cells\n"
		"  s = save current grid      enter = confirm input\n"
		"  l = load a grid                                 \n"
		"  escape = quit                   F11 = fullscreen\n",
		sys->win);
		printed = true;
	}
}

SDL_bool	confirm_message(std::string title, std::string text)
{
	SDL_MessageBoxButtonData buttons[2];
	SDL_MessageBoxColorScheme colorScheme;
	SDL_MessageBoxData messageboxdata;
	int buttonid(0);

	buttons[0] = message_box_button_data(SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 0, "Yes");
	buttons[1] = message_box_button_data(SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 1, "No");
	colorScheme = message_box_color_scheme_init();
	messageboxdata = message_box_data_init(SDL_MESSAGEBOX_INFORMATION, sys->win
										, title.c_str() , text.c_str()
										, SDL_arraysize(buttons), buttons
										, &colorScheme);
	if (SDL_ShowMessageBox(&messageboxdata, &buttonid) < 0)
		throw std::invalid_argument("displaying confirm box");
	if (buttonid == 0)
		return SDL_TRUE;
	return SDL_FALSE;
}

std::string	input_box(const char *text, std::vector<std::string> &proposition
					, unsigned long max_size_entry)
{
	std::string		result("|");
	SDL_Event		e;
	SDL_bool		done(SDL_FALSE);
	unsigned long	index(0);
	int				proposition_index(0);

	system_get_window_size();
	proposition.insert(proposition.end(), "");
	while (done == SDL_FALSE)
	{
		while (SDL_PollEvent(&e) == 1)
		{
			if (e.type == SDL_KEYDOWN)
				catch_input(e, result, index, done, proposition, proposition_index, max_size_entry);
			if (done == SDL_FALSE)
			{
				draw_rect(rect_init(sys->win_size.x / 2 - 150, sys->win_size.y /2 - 50, 300, 100), color_init(10, 70, 160));
				draw_rect(rect_init(sys->win_size.x / 2 - 140, sys->win_size.y /2, 280, 45), color_init(50, 50, 50));
				draw_pretty_text(text, rect_init(sys->win_size.x / 2 - 100, sys->win_size.y /2 - 45, 200, 50), color_init(0, 0, 0));
				draw_pretty_text(result, rect_init(sys->win_size.x / 2 - 135, sys->win_size.y /2 - 5, result.length() * 9, 50), color_init(0, 0, 0));
				SDL_RenderPresent(sys->render);
			}
		}
	}
	result.erase(result.find("|"), 1);
	return result;
}

int	input_nbr_box(const char *text, std::vector<std::string> &proposition
					, unsigned long max_size_entry)
{
	std::string		result("|");
	SDL_Event		e;
	SDL_bool		done(SDL_FALSE);
	unsigned long	index(0);
	int				proposition_index(0);

	system_get_window_size();
	while (done == SDL_FALSE)
	{
		while (SDL_PollEvent(&e) == 1)
		{
			if (e.type == SDL_KEYDOWN)
				catch_nbr_input(e, result, index, done, proposition, proposition_index, max_size_entry);
			draw_rect(rect_init(sys->win_size.x / 2 - 150, sys->win_size.y /2 - 50, 300, 100), color_init(10, 70, 160));
			draw_rect(rect_init(sys->win_size.x / 2 - 140, sys->win_size.y /2, 280, 45), color_init(50, 50, 50));
			draw_pretty_text(text, rect_init(sys->win_size.x / 2 - 100, sys->win_size.y /2 - 45, 200, 50), color_init(0, 0, 0));
			draw_pretty_text(result, rect_init(sys->win_size.x / 2 - 135, sys->win_size.y /2 - 5, result.length() * 9, 50), color_init(0, 0, 0));
			SDL_RenderPresent(sys->render);
		}
	}
	result.erase(result.find("|"), 1);
	return atoi(result.c_str());
}
