#ifndef LIFE_GAME_SYSTEM_HPP
# define LIFE_GAME_SYSTEM_HPP

/**
 *  \brief The load function is a one-time call for a programme.
 * 	It will init everything that must be.
 */
void		load(void);
void		start_window(void);
void		end_program(void);
void		update(void);

/**
 *  \brief Will init all the variables in the global struct system.
 */
void		system_init(void);

/**
 *  \brief Will update the win_size variable with the current size of the window.
 */
void		system_get_window_size(void);

#endif