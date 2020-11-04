/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:33:11 by ldutriez          #+#    #+#             */
/*   Updated: 2020/11/03 16:50:24 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int		main(void)
{
	std::string	str("HI THIS IS BRAIN");
	std::string	*pointer(&str);
	std::string	&reference(str);
	
	std::cout << "Printing from a pointer : " << *pointer << std::endl;
	std::cout << "Printing from a reference : " << reference << std::endl;
	return 0;
}