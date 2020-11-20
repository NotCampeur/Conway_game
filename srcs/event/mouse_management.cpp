#include "life_game.hpp"

// This will handle which tile has to be switch according to the cursor position.
// (Need to correct when you click at the bottom of the screen)

void	click_manager(SDL_Event e)
{
	if (e.type == SDL_MOUSEBUTTONDOWN
		&& e.button.y < (TILE_HEIGHT + 1) * sys->grid_size.y
		&& e.button.x < (TILE_WIDTH + 1) * sys->grid_size.x)
	{
		if (e.button.button == SDL_BUTTON_LEFT)
		{
			sys->mouse_left_hold = SDL_TRUE;
			sys->grid[e.button.y / (TILE_HEIGHT + 1)][e.button.x / (TILE_WIDTH + 1)] = '1';
		}
		else if (e.button.button == SDL_BUTTON_RIGHT)
		{
			sys->mouse_right_hold = SDL_TRUE;
			sys->grid[e.button.y / (TILE_HEIGHT + 1)][e.button.x / (TILE_WIDTH + 1)] = '0';
		}
	}
	else if (e.type == SDL_MOUSEBUTTONUP)
	{
		if (e.button.button == SDL_BUTTON_LEFT)
			sys->mouse_left_hold = SDL_FALSE;
		else if (e.button.button == SDL_BUTTON_RIGHT)
			sys->mouse_right_hold = SDL_FALSE;
	}
}

void	motion_manager(SDL_Event e)
{
	if (e.button.y < (TILE_HEIGHT + 1) * sys->grid_size.y
		&& e.button.x < (TILE_WIDTH + 1) * sys->grid_size.x)
	{
		if (sys->mouse_left_hold == SDL_TRUE && sys->mouse_right_hold == SDL_FALSE)
			sys->grid[e.button.y / (TILE_HEIGHT + 1)][e.button.x / (TILE_WIDTH + 1)] = '1';
		else if (sys->mouse_right_hold == SDL_TRUE && sys->mouse_left_hold == SDL_FALSE)
			sys->grid[e.button.y / (TILE_HEIGHT + 1)][e.button.x / (TILE_WIDTH + 1)] = '0';
	}
}
