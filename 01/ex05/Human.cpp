/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 14:00:55 by ldutriez          #+#    #+#             */
/*   Updated: 2020/09/08 16:13:00 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

			Human::Human() : _brain()
{
}

			Human::~Human()
{
}

const Brain	&Human::getBrain(void) const
{
	return _brain;
}

std::string	Human::identify(void) const
{
	return	_brain.identify();
}