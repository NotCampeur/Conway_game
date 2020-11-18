#include "life_game.hpp"

SDL_MessageBoxButtonData	message_box_button_data(Uint32 flag
													, int buttonid
													, const char *text)
{
	SDL_MessageBoxButtonData result;
	result.flags = flag;
	result.buttonid = buttonid;
	result.text = text;

	return result;
}

SDL_MessageBoxColorScheme	message_box_color_scheme_init(SDL_Color background
														, SDL_Color text
														, SDL_Color button_border
														, SDL_Color button_background
														, SDL_Color button_selected)
{
	SDL_MessageBoxColorScheme result;
	result.colors[SDL_MESSAGEBOX_COLOR_BACKGROUND] = {background.r, background.g, background.b};
	result.colors[SDL_MESSAGEBOX_COLOR_TEXT] = {text.r, text.g, text.b};
	result.colors[SDL_MESSAGEBOX_COLOR_BUTTON_BORDER] = {button_border.r, button_border.g, button_border.b};
	result.colors[SDL_MESSAGEBOX_COLOR_BUTTON_BACKGROUND] = {button_background.r, button_background.g, button_background.b};
	result.colors[SDL_MESSAGEBOX_COLOR_BUTTON_SELECTED] = {button_selected.r, button_selected.g, button_selected.b};
	return result;
}

SDL_MessageBoxData			message_box_data_init(Uint32 flags
												, SDL_Window *window
												, const char *title
												, const char *message
												, int numbuttons
												, const SDL_MessageBoxButtonData *buttons
												, const SDL_MessageBoxColorScheme *colorScheme)
{
	SDL_MessageBoxData result;

	result.flags = flags;
	result.window = window;
	result.title = title;
	result.message = message;
	result.numbuttons = numbuttons;
	result.buttons = buttons;
	result.colorScheme = colorScheme;
	return result;
}