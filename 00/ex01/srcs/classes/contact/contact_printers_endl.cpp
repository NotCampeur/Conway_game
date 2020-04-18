#include "phone_book.hpp"
    
void	c_contact::print_first_name_endl() const
{
    std::cout << "First Name : " << _first_name << std::endl;
}

void	c_contact::print_last_name_endl() const
{
    std::cout << "Last Name : " << _last_name << std::endl;
}

void	c_contact::print_nickname_endl() const
{
    std::cout << "Nickame : " << _nickname << std::endl;
}

void	c_contact::print_login_endl() const
{
    std::cout << "Login : " << _login << std::endl;
}

void	c_contact::print_email_address_endl() const
{
    std::cout << "Email : " << _email_address << std::endl;
}

void	c_contact::print_favorite_meal_endl() const
{
    std::cout << "Favorite Meal : " << _favorite_meal << std::endl;
}

void	c_contact::print_underwear_color_endl() const
{
    std::cout << "Underwear Color : " << _underwear_color << std::endl;
}

void	c_contact::print_darkest_secret_endl() const
{
    std::cout << "Darkest Secret : " << _darkest_secret << std::endl;
}

void	c_contact::print_birthday_date_endl() const
{
    std::cout << "Birthday Date : " << _birthday_date << std::endl;
}

void	c_contact::print_postal_address_endl() const
{
    std::cout << "Postal Address : " << _postal_address << std::endl;
}

void	c_contact::print_phone_number_endl() const
{
    std::cout << "Phone Number : " << _phone_number << std::endl;
}

void	c_contact::print_fill_endl() const
{
    std::cout << _fill << std::endl;
}