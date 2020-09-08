/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 16:25:30 by ldutriez          #+#    #+#             */
/*   Updated: 2020/09/08 16:46:42 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

		HumanB::HumanB() : _weapon(), _name("John")
{

}

		HumanB::HumanB(std::string name, Weapon weapon)
{
	_name = name;
	_weapon = weapon;
}

		HumanB::~HumanB()
{

}

void	HumanB::attack() const
{
	std::cout << _name << " strike with " << _weapon.getType() << std::endl;
}