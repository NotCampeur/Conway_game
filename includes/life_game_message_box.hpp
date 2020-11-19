#ifndef LIFE_GAME_MESSAGE_BOX_HPP
# define LIFE_GAME_MESSAGE_BOX_HPP

/**
 *  \brief Create a button used in message_box_data_init()
 *
 *  \param flag		The SDL_MessageBoxButtonFlags:: used for shortcuts.
 *  \param buttonid	The index of the button.
 *  \param text		The text display on the button.
 *
 *  \return The button is return and ready to use.
 */
SDL_MessageBoxButtonData	message_box_button_data(Uint32 flag
													, int buttonid
													, const char *text);
/**
 *  \brief Create a color scheme used in SDL_ShowMessageBox()
 *
 *  \param background			The color used for the background.
 *  \param text					The color used for the text.
 *  \param button_border		The color used for the buttons borders.
 *  \param button_background	The color used for the buttons background.
 *  \param button_selected		The color used for the buttons background when selected.
 *
 *  \return The color scheme is returned after initialization.
 * 
 */
SDL_MessageBoxColorScheme	message_box_color_scheme_init(SDL_Color background = color_init(116, 116, 128)
														, SDL_Color text = color_init(0, 0, 0)
														, SDL_Color button_border = color_init(0, 0, 0)
														, SDL_Color button_background = color_init(136, 136, 148)
														, SDL_Color button_selected = color_init(0, 255, 0));

/**
 *  \brief Create the data needed for SDL_ShowMessageBox().
 *
 *  \param flags		The flag which precise the type of box.
 *  \param window		The window which the box is bound to.
 *  \param title		The title which will be display.
 *  \param message		The message which will be display.
 *  \param numbuttons	The numbers of buttons in the box.
 *  \param buttons		The pointer to the buttons.
 *  \param colorScheme	The color scheme previously init with message_box_color_scheme_init().
 *
 *  \return The needed data are returned after initialization.
 */
SDL_MessageBoxData			message_box_data_init(Uint32 flags
												, SDL_Window *window
												, const char *title
												, const char *message
												, int numbuttons
												, const SDL_MessageBoxButtonData *buttons
												, const SDL_MessageBoxColorScheme *colorScheme);

#endif