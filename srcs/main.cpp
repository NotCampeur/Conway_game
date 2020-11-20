#include "life_game.hpp"

/**
 *	TODO | Ask the user the size of the grid he want to launch
 *	TODO | Parse the file before the load
 */

int		main()
{
	try
	{
		load();
		update();
		end_program();
	}
	catch (std::invalid_argument &e) 
	{
		std::cerr << "Error : " << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
	return EXIT_SUCCESS;
}
