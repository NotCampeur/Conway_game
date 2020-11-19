#ifndef LIFE_GAME_COLOR_HPP
# define LIFE_GAME_COLOR_HPP

SDL_Color	color_init(Uint8 r = 0, Uint8 g = 0, Uint8 b = 0);
SDL_Color	*color_malloc(Uint8 r = 0, Uint8 g = 0, Uint8 b = 0);
SDL_Color	*color_malloc(SDL_Color color);
void		SDL_SetRenderDrawColor(SDL_Color color);

#endif