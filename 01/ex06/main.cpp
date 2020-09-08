/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 16:25:22 by ldutriez          #+#    #+#             */
/*   Updated: 2020/09/08 16:53:45 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

void	HumanA_test()
{
	Weapon	club;

	club = Weapon("crude spiked club");
	HumanA	bob("Bob", club);
	bob.attack();
	club.setType("FIST");
	bob.attack();
}

void	HumanB_test()
{
	Weapon	club;

	club = Weapon("crude spiked club");
	HumanB	jim("jim");
	jim.setWeapon(club);
	jim.attack();
	club.setType("FIST");
	jim.attack();
}

int		main()
{
	// HumanA_test();
	HumanB_test();
	return 0;
}