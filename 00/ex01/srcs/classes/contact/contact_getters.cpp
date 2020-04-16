#include "../../../includes/phone_book.hpp"
    
std::string	c_contact::get_first_name() const
{
    return _first_name;
}

std::string	c_contact::get_last_name() const
{
    return _last_name;
}

std::string	c_contact::get_nickname() const
{
    return _nickname;
}

std::string	c_contact::get_login() const
{
    return _login;
}

std::string	c_contact::get_email_address() const
{
    return _email_address;
}

std::string	c_contact::get_favorite_meal() const
{
    return _favorite_meal;
}

std::string	c_contact::get_underwear_color() const
{
    return _underwear_color;
}

std::string	c_contact::get_darkest_secret() const
{
    return _darkest_secret;
}

std::string	c_contact::get_birthday_date() const
{
    return _birthday_date;
}

int			c_contact::get_postal_address() const
{
    return _postal_address;
}

int			c_contact::get_phone_number() const
{
    return _phone_number;
}

bool		c_contact::get_fill() const
{
    return _fill;
}