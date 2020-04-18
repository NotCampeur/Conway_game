#include "phone_book.hpp"
    
std::string	c_contact::first_name() const
{
    return _first_name;
}

std::string	c_contact::last_name() const
{
    return _last_name;
}

std::string	c_contact::nickname() const
{
    return _nickname;
}

std::string	c_contact::login() const
{
    return _login;
}

std::string	c_contact::email_address() const
{
    return _email_address;
}

std::string	c_contact::favorite_meal() const
{
    return _favorite_meal;
}

std::string	c_contact::underwear_color() const
{
    return _underwear_color;
}

std::string	c_contact::darkest_secret() const
{
    return _darkest_secret;
}

std::string	c_contact::birthday_date() const
{
    return _birthday_date;
}

std::string	c_contact::postal_address() const
{
    return _postal_address;
}

std::string	c_contact::phone_number() const
{
    return _phone_number;
}

bool		c_contact::fill() const
{
    return _fill;
}