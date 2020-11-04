/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 16:25:26 by ldutriez          #+#    #+#             */
/*   Updated: 2020/11/03 16:56:14 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// CREATORS | DESTRUCTOR

					HumanA::HumanA() :_name("John")
{
	_weapon = NULL;
}

					HumanA::HumanA(std::string name)
{
	_weapon = NULL;
	_name = name;
}

					HumanA::HumanA(std::string name, Weapon &weapon)
{
	_weapon = &weapon;
	_name = name;
}

					HumanA::~HumanA()
{

}

// ACCESSORS

void				HumanA::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

void				HumanA::setName(std::string name)
{
	_name = name;
}

Weapon const		&HumanA::getWeapon(void) const
{
	return *_weapon;
}

std::string	const	&HumanA::getName(void) const
{
	return _name;
}

// METHOD

void				HumanA::attack() const
{
	std::cout << _name << " strike with " << _weapon->getType() << std::endl;
}