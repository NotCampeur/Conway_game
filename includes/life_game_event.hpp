#ifndef LIFE_GAME_EVENT_HPP
# define LIFE_GAME_EVENT_HPP

void		event_manager(void);
void		key_manager(SDL_Event e);
void		click_manager(SDL_Event e);
void		motion_manager(SDL_Event e);
void		scroll_manager(SDL_Event e);
void		movement_manager(SDL_Event e);

#endif