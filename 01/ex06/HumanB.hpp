/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 16:25:11 by ldutriez          #+#    #+#             */
/*   Updated: 2020/09/09 08:45:16 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include "Weapon.hpp"

class HumanB
{
	private:
				Weapon		*_weapon;
				std::string	_name;

	public:

// CREATORS | DESTRUCTOR

						HumanB();
						HumanB(std::string name);
						HumanB(std::string name, Weapon &weapon);
						~HumanB();

// ACCESSORS

	void				setWeapon(Weapon &weapon);
	void				setName(std::string name);

	Weapon const		&getWeapon(void) const;
	std::string	const	&getName(void) const;

// METHOD

	void				attack() const;
};

#endif