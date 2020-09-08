/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 12:23:01 by ldutriez          #+#    #+#             */
/*   Updated: 2020/09/08 11:19:26 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// CONSTRUCTORS | DESTRUCTOR
					Zombie::Zombie()
{
	_type = static_cast<ZombieType>(8);
	_name = "Tom";
}

					Zombie::Zombie(ZombieType type, std::string name)
{
	_type = type;
	_name = name;
}

					Zombie::~Zombie()
{
	
}

// ACCESSORS
Zombie::ZombieType	Zombie::type(void) const
{
	return _type;
}

std::string			Zombie::name(void) const
{
	return _name;
}

std::string			Zombie::type_str(void) const
{
	std::string result("Basic");

	if (_type == ZombieType::boomer)
		result.assign("Boomer");
	else if (_type == ZombieType::hunter)
		result.assign("Hunter");
	else if (_type == ZombieType::smoker)
		result.assign("Smoker");
	else if (_type == ZombieType::tank)
		result.assign("Tank");
	else if (_type == ZombieType::charger)
		result.assign("Charger");
	else if (_type == ZombieType::jockey)
		result.assign("Jockey");
	else if (_type == ZombieType::spitter)
		result.assign("Spitter");
	else if (_type == ZombieType::witch)
		result.assign("Witch");
	return result;
}

void				Zombie::set_type(ZombieType type)
{
	_type = type;
}

void				Zombie::set_name(std::string name)
{
	_name = name;
}

// METHOD
void				Zombie::advert(void) const
{
	std::cout << _name << " the " << type_str() << " wander" << std::endl;
}

void				Zombie::announce() const
{
	std::cout << _name << " the Zombie is a " << type_str() << std::endl;
}

void				Zombie::rand_name_gen()
{
	_name.clear();
	int			name_size(0);

	name_size = 3 + rand() % 5;
	for (int i(0); i < name_size; i++)
	{
		_name.push_back(97 + rand() % 26);
	}
}