/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:07:24 by ldutriez          #+#    #+#             */
/*   Updated: 2020/11/05 14:37:09 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <exception>

static void	cat_terminal(void)
{
	std::string	str;

	while (1)
	{
		getline(std::cin, str);
		std::cout << str << std::endl;
	}
}

static void	cat_file(char *file_name)
{
	std::ifstream	file;
	std::string		str;
	
	file.open(file_name);
	if (file.is_open() == false)
	{
		std::cerr << "cat: " << file_name << ": File does not exist" << std::endl;
		return ;
	}
	while (getline(file, str))
	std::cout << str << std::endl;
	file.close();
}

int			main(int argc, char *argv[])
{
	if (argc == 1)
		cat_terminal();
	else
	{
		for (int i(1); i < argc; i++)
			cat_file(argv[i]);
	}
	return 0;
}
