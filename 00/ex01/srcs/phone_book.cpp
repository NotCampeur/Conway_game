#include <iostream>
#include <string>

int		main(void)
{
	std::string answer;

	std::cout << "Welcome in your phone book! You can type add | search | exit" << std::endl;
	while (answer != "exit")
	{
		std::cin >> answer;
		if (answer == "add")
		{

		}
		else if (answer == "search")
		{

		}
		else if (answer != "exit")
			answer.clear();
	}
	std::cout << "Goodbye." << std::endl;
	return 0;
}
