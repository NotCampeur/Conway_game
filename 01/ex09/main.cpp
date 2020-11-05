/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:37:57 by ldutriez          #+#    #+#             */
/*   Updated: 2020/11/05 14:05:01 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

int		main()
{
	Logger	logger("wtf");

	logger.log("Console", "This is a test");
	logger.log("File", "This is a file test");
	logger.log("File", "which I hope work");
	return 0;
}