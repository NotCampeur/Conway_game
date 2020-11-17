#ifndef LIFE_GAME_EXTERN_HPP
# define LIFE_GAME_EXTERN_HPP

# include "life_game_define.hpp"


typedef struct			s_system
{
	SDL_Window			*win;
	SDL_Renderer		*render;
	unsigned long int	gen_count;
	int					grid[GRID_WIDTH][GRID_HEIGHT]{};
	SDL_bool			interrupt;
	SDL_bool			auto_run;
	SDL_bool			fullscreen;
	SDL_Rect			cam;
	TTF_Font			*font;
}						t_system;

extern t_system *sys;

void	system_malloc(void);

#endif
