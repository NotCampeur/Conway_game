#include "phone_book.hpp"

void    add_first_name(c_contact &contact)
{
    std::string answer;

    std::cout << "Enter the first name please:" << std::endl;
	std::getline(std::cin, answer);
	contact.set_first_name(answer);
}

void    add_last_name(c_contact &contact)
{
    std::string answer;

	std::cout << "Enter the last name please:" << std::endl;
	std::getline(std::cin, answer);
	contact.set_last_name(answer);
}

void    add_nickname(c_contact &contact)
{
    std::string answer;

	std::cout << "Enter the nickname please:" << std::endl;
	std::getline(std::cin, answer);
	contact.set_nickname(answer);
}	

void    add_login(c_contact &contact)
{
    std::string answer;

	std::cout << "Enter the login please:" << std::endl;
	std::getline(std::cin, answer);
	contact.set_login(answer);
}	

void    add_email_address(c_contact &contact)
{
    std::string answer;

	std::cout << "Enter the email address please:" << std::endl;
	std::getline(std::cin, answer);
	contact.set_email_address(answer);
}

void    add_favorite_meal(c_contact &contact)
{
    std::string answer;

	std::cout << "Enter the favorite meal please:" << std::endl;
	std::getline(std::cin, answer);
	contact.set_favorite_meal(answer);
}

void    add_underwear_color(c_contact &contact)
{
    std::string answer;

	std::cout << "Enter the underwear color it's for a friend:" << std::endl;
	std::getline(std::cin, answer);
	contact.set_underwear_color(answer);
}

void    add_darkest_secret(c_contact &contact)
{
    std::string answer;

	std::cout << "Enter the darkest secret please:" << std::endl;
	std::getline(std::cin, answer);
	contact.set_darkest_secret(answer);
}

void    add_birthday_date(c_contact &contact)
{
    std::string answer;

	std::cout << "Enter the birthday date please:" << std::endl;
	std::getline(std::cin, answer);
	contact.set_birthday_date(answer);
}

void    add_postal_address(c_contact &contact)
{
    std::string answer;

	std::cout << "Enter the postal address please:" << std::endl;
	std::getline(std::cin, answer);
	contact.set_postal_address(answer.c_str());
}

void    add_phone_number(c_contact &contact)
{
    std::string answer;

	std::cout << "Enter the phone number please:" << std::endl;
	std::getline(std::cin, answer);
	contact.set_phone_number(answer.c_str());
}