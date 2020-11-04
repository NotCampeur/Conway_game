/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 15:00:49 by ldutriez          #+#    #+#             */
/*   Updated: 2020/11/04 16:16:31 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int		main()
{
	Human	tom;

	tom.action("meleeAttack", "segfaults");
	tom.action("rangedAttack", "leaks");
	tom.action("intimidatingShoot", "bugs");
	return 0;
}