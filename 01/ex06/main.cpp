/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 16:25:22 by ldutriez          #+#    #+#             */
/*   Updated: 2020/11/03 17:05:29 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

void	HumanA_test()
{
	Weapon	club = Weapon("Steel longsword");

	HumanA	bob("Bob", club);
	bob.attack();
	club.setType("BONK");
	bob.attack();
}

void	HumanB_test()
{
	Weapon	club = Weapon("crude spiked club");

	HumanB	jim("jim");
	jim.attack();
	jim.setWeapon(club);
	jim.attack();
	club.setType("Ak47");
	jim.attack();
}

int		main()
{
	HumanA_test();
	HumanB_test();
	return 0;
}