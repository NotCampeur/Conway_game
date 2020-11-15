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
void		SDL_SetRenderDrawColor(SDL_Renderer *render, SDL_Color color);

/*
**	EVENT
*/

void		event_manager(SDL_Window *win, SDL_bool *interrupt);
void		key_manager(SDL_Window *win, SDL_Event e, SDL_bool *interrupt);
void		click_manager(SDL_Event e);
void		scroll_manager(SDL_Event e);

/*
**	RENDER
*/

void	render_screen(SDL_Window *win, SDL_Renderer *render);
void	draw_grid(SDL_Renderer *render);

/*
**	SYSTEM
*/

void	load(SDL_Window **win, SDL_Renderer **render);
void	start_window(SDL_Window **win, SDL_Renderer **render);
void	end_program(SDL_Window *win, SDL_Renderer *render);

/*
**	UPDATE
*/

void	update(SDL_Window *win, SDL_Renderer *render);

/*
**	ENGINE
*/

void	next_gen(void);

#endif
