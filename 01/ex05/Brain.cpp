/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 14:00:38 by ldutriez          #+#    #+#             */
/*   Updated: 2020/11/03 16:30:53 by ldutriez         ###   ########.fr       */
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
	std::stringstream	str_stream;
    std::string 		result;
    
    str_stream << this;
	result = str_stream.str();
    return result;
}