#include "life_game.hpp"

int		main()
{
	SDL_Window		*win(NULL);
	SDL_Renderer	*render(NULL);

	try
	{
		load(&win, &render);
		update(&win, &render);
		end_program(win, render);
	}
	catch (std::invalid_argument &e) 
	{
		std::cerr << "Error : " << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
