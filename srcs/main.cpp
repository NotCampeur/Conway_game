#include "life_game.hpp"

/**
 *	TODO | Add a struct / class for the input box data.
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
	return EXIT_SUCCESS;
}
