
class c_contact
{
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_login;
	std::string	_email_address;
	std::string	_favorite_meal;
	std::string	_underwear_color;
	std::string	_darkest_secret;
	int		_postal_address;
	int		_phone_number;
	int		_birthday_date;
public:
			c_contact();
			~c_contact();

	std::string	get_first_name() const;
	std::string	get_last_name() const;
	std::string	get_nickname() const;
	std::string	get_login() const;
	std::string	get_email_address() const;
	std::string	get_favorite_meal() const;
	std::string	get_underwear_color() const;
	std::string	get_darkest_secret() const;
	int		get_postal_address() const;
	int		get_phone_number() const;
	int		get_birthday_date() const;

	void		set_first_name(std::string first_name);
	void		set_last_name(std::string last_name);
	void		set_nickname(std::string nickname);
	void		set_login(std::string login);
	void		set_email_address(std::string email_address);
	void		set_favorite_meal(std::string favorite_meal);
	void		set_underwear_color(std::string underwear_color);
	void		set_darkest_secret(std::string darkest_secret);
	void		set_postal_address(int postal_address);
	void		set_phone_number(int phone_number);
	void		set__birthday_date(int birthday_date);

	void		print_first_name() const;
	void		print_last_name() const;
	void		print_nickname() const;
	void		print_login() const;
	void		print_email_address() const;
	void		print_favorite_meal() const;
	void		print_underwear_color() const;
	void		print_darkest_secret() const;
	void		print_postal_address() const;
	void		print_phone_number() const;
	void		print_birthday_date() const;
};
