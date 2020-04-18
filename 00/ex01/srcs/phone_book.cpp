#include "phone_book.hpp"

static std::string	format_string(std::string input)
{
	std::string	result;
	int	space_nbr(0);

	space_nbr = 10 - input.size();
	result.push_back('|');
	if (space_nbr < 0)
	{
		for (int i(0); i < 9; i++)
			result.push_back(input[i]);
		result.push_back('.');
	}
	else
	{
		for (int i(0); i < space_nbr; i++)
			result.push_back(' ');
		result.append(input);
	}
	return result;
}

static void	print_main_infos(c_contact const phone_book[8])
{
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	for (int i(0); i < 8; i++)
	{
		std::cout << "|" << "         " << i + 1;
		std::cout << format_string(phone_book[i].first_name());
		std::cout << format_string(phone_book[i].last_name());
		std::cout << format_string(phone_book[i].login()) << '|' << std::endl;
	}
}

static void	search_contact(c_contact const phone_book[8])
{
	int		input(0);

	print_main_infos(phone_book);
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while (input <= 0 || input >= 9)
	{
		std::cout << "Choose an index" << std::endl;
		std::cin >> input;
	}
	input--;
	phone_book[input].print_first_name_endl();
	phone_book[input].print_last_name_endl();
	phone_book[input].print_nickname_endl();
	phone_book[input].print_login_endl();
	phone_book[input].print_email_address_endl();
	phone_book[input].print_favorite_meal_endl();
	phone_book[input].print_underwear_color_endl();
	phone_book[input].print_darkest_secret_endl();
	phone_book[input].print_birthday_date_endl();
	phone_book[input].print_postal_address_endl();
	phone_book[input].print_phone_number_endl();
}

static void	add_contact(c_contact phone_book[8])
{
	int			index(0);

	while (phone_book[index].fill() == true)
	{
		index++;
		if (index == 8)
			index = 0;
	}
	if (index < 7)
		phone_book[index + 1].set_fill(false);
	else if (index == 7)
		phone_book[0].set_fill(false);
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	add_first_name(phone_book[index]);
	add_last_name(phone_book[index]);
	add_nickname(phone_book[index]);
	add_login(phone_book[index]);
	add_email_address(phone_book[index]);
	add_favorite_meal(phone_book[index]);
	add_underwear_color(phone_book[index]);
	add_darkest_secret(phone_book[index]);
	add_birthday_date(phone_book[index]);
	add_postal_address(phone_book[index]);
	add_phone_number(phone_book[index]);
	phone_book[index].set_fill(true);
}

int		main(void)
{
	std::string answer;
	c_contact	phone_book[8];

	std::cout << "Welcome in your phone book!" << std::endl;
	while (answer != "exit")
	{
		std::cout << std::endl << "You can type add | search | exit" << std::endl;
		std::cin >> answer;
		if (answer == "add")
			add_contact(phone_book);
		else if (answer == "search")
			search_contact(phone_book);
		else if (answer != "exit")
			answer.clear();
	}
	std::cout << "Goodbye." << std::endl;
	return 0;
}
