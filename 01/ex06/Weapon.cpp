/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 16:25:17 by ldutriez          #+#    #+#             */
/*   Updated: 2020/09/09 08:24:29 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.hpp"

			Weapon::Weapon()
{
	_type = "fist";
}

			Weapon::Weapon(std::string type)
{
	_type = type;
}

			Weapon::~Weapon()
{

}

std::string	const &Weapon::getType() const
{
	return _type;
}

void		Weapon::setType(std::string type)
{
	_type = type;
}