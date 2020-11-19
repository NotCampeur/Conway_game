#ifndef LIFE_GAME_POINT_HPP
# define LIFE_GAME_POINT_HPP

SDL_Point	point_init(int x, int y);
SDL_Point	*point_malloc(int x, int y);
SDL_Point	*point_malloc(SDL_Point pos);

#endif