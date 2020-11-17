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
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
