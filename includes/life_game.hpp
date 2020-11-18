#ifndef LIFE_GAME_HPP
# define LIFE_GAME_HPP

# include "life_game_includes.hpp"

/*
**	RECT FUNCTIONS
*/

SDL_Rect	rect_init(int x, int y, int w, int h);
SDL_Rect	*rect_malloc(int x, int y, int w, int h);
SDL_Rect	*rect_malloc(SDL_Rect pos);

/*
**	POINT FUNCTIONS
*/

SDL_Point	point_init(int x, int y);
SDL_Point	*point_malloc(int x, int y);
SDL_Point	*point_malloc(SDL_Point pos);

/*
**	COLOR FUNCTIONS
*/

SDL_Color	color_init(Uint8 r = 0, Uint8 g = 0, Uint8 b = 0);
SDL_Color	*color_malloc(Uint8 r = 0, Uint8 g = 0, Uint8 b = 0);
SDL_Color	*color_malloc(SDL_Color color);
void		SDL_SetRenderDrawColor(SDL_Color color);

/*
**	MESSAGE BOX
*/

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
 */
SDL_MessageBoxColorScheme	message_box_color_scheme_init(SDL_Color background = color_init(255, 0, 0)
														, SDL_Color text = color_init(0, 255, 0)
														, SDL_Color button_border = color_init(255, 255, 0)
														, SDL_Color button_background = color_init(0, 0, 255)
														, SDL_Color button_selected = color_init(255, 0, 255));

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

/*
**	EVENT
*/

void		event_manager(void);
void		key_manager(SDL_Event e);
void		click_manager(SDL_Event e);
void		motion_manager(SDL_Event e);
void		scroll_manager(SDL_Event e);
void		movement_manager(SDL_Event e);

/*
**	RENDER
*/

void		render_screen(void);
void		render_texture(SDL_Texture **tex, SDL_Rect *src = NULL, SDL_Rect *dst = NULL, bool horizontal_flip = false);
void		draw_grid(void);
void		set_draw_color(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

/*
**	SYSTEM
*/

void		load(void);
void		start_window(void);
void		end_program(void);

/*
**	UPDATE
*/

void		update(void);

/*
**	ENGINE
*/

void		next_gen(void);
void		clear_grid(void);
void		random_grid(void);
void		save_grid(void);
void		welcome_message(void);
SDL_bool	confirm_message(std::string title, std::string text);
std::string	input_box(void);

/*
**	TEXTURE
*/

SDL_Texture	**create_image_texture(std::string path);
SDL_Texture	**create_texture(SDL_Surface *surface);

/*
**	TEXT
*/

void	draw_text(std::string to_print, SDL_Rect *pos, SDL_Color color);
void	draw_pretty_text(std::string to_print, SDL_Rect *pos, SDL_Color color);

#endif
