#ifndef LIFE_GAME_EXTERN_HPP
# define LIFE_GAME_EXTERN_HPP

# include "life_game_define.hpp"

typedef struct			s_system
{
	SDL_Window			*win;
	SDL_Renderer		*render;
	unsigned long int	gen_count;
	int					grid[GRID_HEIGHT][GRID_WIDTH]{};
	SDL_bool			interrupt;
	SDL_bool			auto_run;
	SDL_bool			fullscreen;
	SDL_bool			mouse_left_hold;
	SDL_bool			mouse_right_hold;
	SDL_Rect			cam;
	TTF_Font			*font;
	SDL_Point			win_size;
}						t_system;

extern t_system *sys;

#endif
