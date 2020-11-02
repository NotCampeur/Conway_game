/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 11:25:35 by ldutriez          #+#    #+#             */
/*   Updated: 2020/11/02 17:40:44 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

	ZombieHorde::ZombieHorde()
{
	_zombies = NULL;
	_nZombie = 0;
}

	ZombieHorde::ZombieHorde(int n)
{
	_zombies = new Zombie[n];
	srand(time(NULL));
	for (int i(0); i < n; i++)
	{
		_zombies[i].set_type(static_cast<Zombie::ZombieType>(rand() % 9));
		_zombies[i].rand_name_gen();
	}
	_nZombie = n;
}

	ZombieHorde::~ZombieHorde()
{
		delete [] _zombies;
}

void	ZombieHorde::announce() const
{
	for	(int i(0); i < _nZombie; i++)
		_zombies[i].announce();
}

Zombie	&ZombieHorde::operator[](int n)
{
	Zombie *result(NULL);
	
	if (n < 0 || n >= _nZombie)
		std::cout << "Error using the [] operator, wrong index" << std::endl;
	else
		result = &_zombies[n];
	return *result;
}