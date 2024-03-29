#ifndef LIFE_GAME_EXTERN_HPP
# define LIFE_GAME_EXTERN_HPP

# include "life_game_define.hpp"

typedef struct			s_system
{
	SDL_Window			*win;
	SDL_Renderer		*render;
	SDL_Point			grid_size;
	SDL_Point			win_size;
	char				**grid;
	unsigned long int	gen_count;
	SDL_bool			interrupt;
	SDL_bool			auto_run;
	SDL_bool			fullscreen;
	SDL_bool			mouse_left_hold;
	SDL_bool			mouse_right_hold;
	TTF_Font			*font;
}						t_system;

extern t_system *sys;

#endif
