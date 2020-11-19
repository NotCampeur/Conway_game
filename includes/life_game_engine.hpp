#ifndef LIFE_GAME_ENGINE_HPP
# define LIFE_GAME_ENGINE_HPP

/**
 *  \brief Will apply the game rules on the current grid to go to the next generation.
 */
void		next_gen(void);

/**
 *  \brief Set all the cells of the grid to 0.
 */
void		clear_grid(void);

/**
 *  \brief Create random generated grid.
 */
void		random_grid(void);

/**
 *  \brief Will attempt to save the current grid by asking the user the destination file name.
 */
void		save_grid(void);

/**
 *  \brief Create a dialog box with a message and a list of the command.
 */
void		welcome_message(void);

/**
 *  \brief Create a dialog box with two buttons "Yes" | "No".
 *
 *  \param title	The box window title.
 *  \param text		The text that will be displayed.
 *
 *  \return SDL_TRUE if "Yes" has been pressed, SDL_FALSE if not.
 */
SDL_bool	confirm_message(std::string title, std::string text);

/**
 *  \brief Create a dialog box to take the user's input.
 *  Only the letters, the numbers, the - and the _ are catch.
 *
 *  \param text	The text that will be displayed.
 *
 *  \return The user's input are return after they hit hte return button.
 */
std::string	input_box(const char *text);

/**
 *  \brief Will check the keypressed to act on the input string.
 *
 *  \param e		The event to check.
 *  \param string	The string where the input will be store.
 *  \param index	The position of the cursor in the string.
 *  \param done		The boolean which tell if the user has finished.
 *
 */
void		catch_input(SDL_Event e, std::string &string, unsigned long &index, SDL_bool &done);

/**
 *  \brief Will add to the string the input where the cursor is located.
 *
 *  \param e		The event to check.
 *  \param string	The string where the input will be store.
 *  \param index	The position of the cursor in the string.
 *
 */
void		insert_typed_input(SDL_Event e, std::string &string, unsigned long &index);

/**
 *  \brief Will remove the character before the cursor.
 *
 *  \param string	The string where the character will be removed.
 *  \param index	The position of the cursor in the string.
 *
 */
void		backspace_typed_input(std::string &string, unsigned long &index);

/**
 *  \brief Will remove the character after the cursor.
 *
 *  \param string	The string where the character will be removed.
 *  \param index	The position of the cursor in the string.
 *
 */
void		delete_typed_input(std::string &string, unsigned long &index);

/**
 *  \brief Will move the cursor to the left in the string.
 *
 *  \param string	The string where the cursor will be moved.
 *  \param index	The position of the cursor in the string.
 *
 */
void		move_left_in_input(std::string &string, unsigned long &index);

/**
 *  \brief Will move the cursor to the right in the string.
 *
 *  \param string	The string where the cursor will be moved.
 *  \param index	The position of the cursor in the string.
 *
 */
void		move_right_in_input(std::string &string, unsigned long &index);

#endif