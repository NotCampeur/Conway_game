#include "../includes/phone_book.hpp"

void	search_contact(c_contact annuaire[8])
{
	int		input;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	for (int i(0); i < 8; i++)
	{
		std::cout << "|" << "         " << i + 1;
		std::cout << "|" << annuaire[i].get_first_name();
		std::cout << "|" << annuaire[i].get_last_name();
		std::cout << "|" << annuaire[i].get_login() << "|" << std::endl;
	}
	std::cout << "Choose an index" << std::endl;
	std::cin >> input;
	input--;
	annuaire[input].print_first_name_endl();
	annuaire[input].print_last_name_endl();
	annuaire[input].print_nickname_endl();
	annuaire[input].print_login_endl();
	annuaire[input].print_email_address_endl();
	annuaire[input].print_favorite_meal_endl();
	annuaire[input].print_underwear_color_endl();
	annuaire[input].print_darkest_secret_endl();
	annuaire[input].print_birthday_date_endl();
	annuaire[input].print_postal_address_endl();
	annuaire[input].print_phone_number_endl();
}

void	add_contact(c_contact annuaire[8])
{
	std::string	answer;
	int			index(0);

	while (annuaire[index].get_fill() == true)
	{
		index++;
		if (index == 8)
		{
			index = 1;
			annuaire[index].set_fill(false);
		}
	}
	add_first_name(annuaire[index]);
	add_last_name(annuaire[index]);
	add_nickname(annuaire[index]);
	add_login(annuaire[index]);
	add_email_address(annuaire[index]);
	add_favorite_meal(annuaire[index]);
	add_underwear_color(annuaire[index]);
	add_darkest_secret(annuaire[index]);
	add_birthday_date(annuaire[index]);
	add_postal_address(annuaire[index]);
	add_phone_number(annuaire[index]);

	annuaire[index].set_fill(true);
}

int		main(void)
{
	std::string answer;
	c_contact	annuaire[8];

	std::cout << "Welcome in your phone book!" << std::endl;
	while (answer != "exit")
	{
		std::cout << std::endl << "You can type add | search | exit" << std::endl;
		std::cin >> answer;
		if (answer == "add")
			add_contact(annuaire);
		else if (answer == "search")
			search_contact(annuaire);
		else if (answer != "exit")
			answer.clear();
	}
	std::cout << "Goodbye." << std::endl;
	return 0;
}
