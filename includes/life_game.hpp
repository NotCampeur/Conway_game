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

SDL_Color	color_init(Uint8 r, Uint8 g, Uint8 b);
SDL_Color	*color_malloc(Uint8 r, Uint8 g, Uint8 b);
SDL_Color	*color_malloc(SDL_Color color);
void		SDL_SetRenderDrawColor(SDL_Color color);

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

/*
**	TEXTURE
*/

SDL_Texture	**create_image_texture(std::string path);
SDL_Texture	**create_texture(SDL_Surface *surface);

/*
**	TEXT
*/

void	draw_text(std::string to_print, SDL_Rect *pos, SDL_Color color);

#endif
