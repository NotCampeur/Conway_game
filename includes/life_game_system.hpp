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

/**
 *  \brief Will rezise the grid according to the sys->grid_size variable.
 */
void		system_init_grid(void);

/**
 *  \brief Will load the grid according to the parameter.
 * 
 *  \param flux	The file to load from.
 */
void		system_load_grid(std::ifstream &flux);

/**
 *  \brief Will free the memory of the grid.
 */
void		system_delete_grid(void);

#endif
