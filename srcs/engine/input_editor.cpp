#include "life_game.hpp"

void	insert_typed_input(SDL_Event e, std::string &string, unsigned long &index)
{
	const Uint8		*keystates = SDL_GetKeyboardState(NULL);

	if ((keystates[SDL_SCANCODE_RSHIFT] || keystates[SDL_SCANCODE_LSHIFT])
			&& (e.key.keysym.sym >= SDLK_a && e.key.keysym.sym <= SDLK_z))
		e.key.keysym.sym = e.key.keysym.sym - 32;
	else if ((keystates[SDL_SCANCODE_RSHIFT] || keystates[SDL_SCANCODE_LSHIFT])
			&& (e.key.keysym.sym == SDLK_MINUS))
		e.key.keysym.sym = '_';
	if ((index + 1) < MAX_SAVE_FILE_NAME)
	{
		string.insert(index, 1, e.key.keysym.sym);
		(index)++;
	}
}

void	backspace_typed_input(std::string &string, unsigned long &index)
{
	if (index > 0)
	{
		string.erase(index - 1, 1);
		index--;
	}
}

void	delete_typed_input(std::string &string, unsigned long &index)
{
	if (index + 1 < string.size())
		string.erase(index + 1, 1);
}

void	move_left_in_input(std::string &string, unsigned long &index)
{
	if (index > 0)
	{
		std::swap(string[index], string[index - 1]);
		index--;
	}
}

void	move_right_in_input(std::string &string, unsigned long &index)
{
	if (index + 1 < string.size())
	{
		std::swap(string[index], string[index + 1]);
		index++;
	}
}

void	catch_input(SDL_Event e, std::string &string, unsigned long &index, SDL_bool &done)
{
	if (e.key.keysym.sym == SDLK_RETURN && string.size() >= 2)
		done = SDL_TRUE;
	else if ((e.key.keysym.sym >= SDLK_a && e.key.keysym.sym <= SDLK_z)
			|| (e.key.keysym.sym >= SDLK_0 && e.key.keysym.sym <= SDLK_9)
			|| e.key.keysym.sym == SDLK_MINUS)
		insert_typed_input(e, string, index);
	else if (e.key.keysym.sym == SDLK_BACKSPACE)
		backspace_typed_input(string, index);
	else if (e.key.keysym.sym == SDLK_DELETE)
		delete_typed_input(string, index);
	else if (e.key.keysym.sym == SDLK_LEFT)
		move_left_in_input(string, index);
	else if (e.key.keysym.sym == SDLK_RIGHT)
		move_right_in_input(string, index);
}