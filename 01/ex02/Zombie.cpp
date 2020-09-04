/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 12:23:01 by ldutriez          #+#    #+#             */
/*   Updated: 2020/09/04 14:37:51 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// CONSTRUCTORS | DESTRUCTOR
					Zombie::Zombie()
{
	_type = ZombieType::basic;
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
	std::cout << "The " 
}