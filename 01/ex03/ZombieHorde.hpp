/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 11:20:06 by ldutriez          #+#    #+#             */
/*   Updated: 2020/11/02 17:08:34 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HORDE_HPP
# define ZOMBIE_HORDE_HPP

#include "Zombie.hpp"

class ZombieHorde
{
	private:
		Zombie	*_zombies;
		int		_nZombie;
	public:

// CONSTRUCTORS | DESTRUCTOR
			ZombieHorde();
			ZombieHorde(int n);
			~ZombieHorde();

// METHOD
	void	announce() const;

// OPERATOR
	Zombie	&operator[](int n);
};

#endif