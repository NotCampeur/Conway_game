/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 16:25:30 by ldutriez          #+#    #+#             */
/*   Updated: 2020/11/03 17:11:28 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

// CREATORS | DESTRUCTOR

					HumanB::HumanB() :_name("John")
{
	_weapon = NULL;
}

					HumanB::HumanB(std::string name)
{
	_weapon = NULL;
	_name = name;
}

					HumanB::HumanB(std::string name, Weapon &weapon)
{
	_weapon = &weapon;
	_name = name;
}

					HumanB::~HumanB()
{

}

// ACCESSORS

void				HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

void				HumanB::setName(std::string name)
{
	_name = name;
}

Weapon const		&HumanB::getWeapon(void) const
{
	return *_weapon;
}

std::string const	&HumanB::getName(void) const
{
	return _name;
}

// METHOD

void				HumanB::attack() const
{
	if (_weapon != NULL)
		std::cout << _name << " strike with " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " strike with nothing" << std::endl;
}