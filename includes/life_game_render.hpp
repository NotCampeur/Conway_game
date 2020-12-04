#ifndef LIFE_GAME_RENDER_HPP
# define LIFE_GAME_RENDER_HPP

void		render_screen(void);
void		render_texture(SDL_Texture **tex, SDL_Rect *src = NULL, SDL_Rect *dst = NULL, bool horizontal_flip = false);
void		draw_grid(void);
void		set_draw_color(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
void		draw_rect(SDL_Rect rect, SDL_Color color);
void		set_draw_color(SDL_Color color);
void		set_draw_color(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
void		draw_load_list(std::vector<std::string>	file_names);

#endif