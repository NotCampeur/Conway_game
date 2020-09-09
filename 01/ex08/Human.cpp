/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 15:01:23 by ldutriez          #+#    #+#             */
/*   Updated: 2020/09/09 16:39:13 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

void	Human::meleeAttack(std::string const &target)
{
	std::cout << "the human punch the " << target << std::endl;
}

void	Human::rangedAttack(std::string const &target)
{
	std::cout << "the human shoot the " << target << std::endl;
}

void	Human::intimidatingShout(std::string const &target)
{
	std::cout << "the human scream at the " << target << std::endl;
}

void	Human::action(std::string const &action_name, std::string const &target)
{
	int	i(0);
	void (Human::*ptr[3])(std::string const &target) = {&Human::meleeAttack,
														&Human::rangedAttack,
														&Human::intimidatingShout};
	std::string	availableAction[3] = {"meleeAttack",
									"rangedAttack",
									"intimidatingShoot"};
	while (i < 3)
	{
		if (availableAction[i] == action_name)
			(this->*ptr[i])(target);
		i++;
	}

}