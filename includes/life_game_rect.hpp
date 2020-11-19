#ifndef LIFE_GAME_RECT_HPP
# define LIFE_GAME_RECT_HPP

SDL_Rect	rect_init(int x, int y, int w, int h);
SDL_Rect	*rect_malloc(int x, int y, int w, int h);
SDL_Rect	*rect_malloc(SDL_Rect pos);

#endif
