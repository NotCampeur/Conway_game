#include "life_game.hpp"

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
