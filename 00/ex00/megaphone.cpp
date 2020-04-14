
#include <iostream>
#include <string>

std::string	to_upper_str(std::string p_str)
{
	std::string	result;

	for(size_t i(0); i < p_str.size(); i++)
		result.push_back(std::toupper(p_str[i]));
	return result;
}

int	main(int ac, char *av[])
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		for(int i(1); i < ac; i++)
			std::cout << to_upper_str(av[i]);
		std::cout << std::endl;
	}
	return 0;
}
