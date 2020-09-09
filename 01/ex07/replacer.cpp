/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 08:51:41 by ldutriez          #+#    #+#             */
/*   Updated: 2020/09/09 12:07:09 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replacer.hpp"

system_data *sys = new system_data;

bool	replace_occurence(std::string &current_str)
{
	current_str.replace(current_str.find);
	return true;
}

bool	manage_files()
{
	std::ifstream	input_file;
	std::ofstream	output_file;
	std::string 	current_line;

	input_file.open(sys->filename());
	output_file.open(sys->filename() + ".replace");
	if (input_file.is_open() == false)
		return false;
	while (getline(input_file, current_line))
	{
		replace_occurence(current_line);
		output_file << current_line << std::endl;
	}
	output_file.close();
	input_file.close();
	return true;
}

int		main(int argc, char *argv[])
{
	if (argc == 4)
	{
		sys->set_argv(argv);
		manage_files();
	}
	else
		std::cout << "Arguments issue" << std::endl;

	return 0;
}