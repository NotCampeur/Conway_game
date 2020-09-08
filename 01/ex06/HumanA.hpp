/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 16:24:59 by ldutriez          #+#    #+#             */
/*   Updated: 2020/09/08 16:44:25 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include "Weapon.hpp"

class HumanA
{
	private:
		Weapon		_weapon;
		std::string	_name;

	public:

// CREATORS | DESTRUCTOR

	HumanA();
	HumanA(std::string name, Weapon weapon);
	~HumanA();
// METHOD

	void	attack() const;
};

#endif