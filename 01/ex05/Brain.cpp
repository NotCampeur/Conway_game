/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 14:00:38 by ldutriez          #+#    #+#             */
/*   Updated: 2020/09/08 16:01:33 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Brain.hpp"

	Brain::Brain()
{

}

	Brain::~Brain()
{

}

std::string	Brain::identify(void) const
{
	std::string result;
	char 		*addr;

	addr = new char;
	sprintf(addr, "%p", this);
	result += addr;
	delete addr;
	return result;
}