/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 16:25:26 by ldutriez          #+#    #+#             */
/*   Updated: 2020/09/08 16:45:33 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

		HumanA::HumanA() : _weapon(), _name("John")
{

}

		HumanA::HumanA(std::string name, Weapon weapon)
{
	_name = name;
	_weapon = weapon;
}

		HumanA::~HumanA()
{

}

void	HumanA::attack() const
{
	std::cout << _name << " strike with " << _weapon.getType() << std::endl;
}