/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 16:25:06 by ldutriez          #+#    #+#             */
/*   Updated: 2020/09/08 16:41:45 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
	private:
		std::string	_type;

	public:
// CONSTRUCTORS | DESTRUCTOR

				Weapon();
				Weapon(std::string type);
				~Weapon();

// ACCESSORS

	std::string	getType() const;

	void		setType(std::string type);
};

#endif