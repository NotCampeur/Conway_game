/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 08:51:41 by ldutriez          #+#    #+#             */
/*   Updated: 2020/11/04 15:50:42 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system_data.hpp"

system_data *sys = new system_data;

static void	replace_occurence(std::string &current_str)
{
	size_t		pos(0);
	std::string	tmp(current_str);
	
	pos = current_str.find(sys->to_replace());
	while (pos != std::string::npos)
	{
		current_str.erase(pos, sys->to_replace().size());
		current_str.insert(pos, sys->replacement());
		pos = current_str.find(sys->to_replace(), pos + sys->replacement().size());
	}
}

static void	manage_files()
{
	std::ifstream	input_file;
	std::ofstream	output_file;
	std::string 	current_line;

	input_file.open(sys->filename());
	if (input_file.is_open() == false)
		throw std::invalid_argument("the filename is not correct");
	output_file.open(sys->filename() + ".replace");
	if (output_file.is_open() == false)
		throw std::invalid_argument("the output file can not be open");
	while (getline(input_file, current_line))
	{
		replace_occurence(current_line);
		output_file << current_line << std::endl;
	}
	output_file.close();
	input_file.close();
}

__attribute__ ((destructor))
static void	exiting(void)
{
	delete sys;
}

int			main(int argc, char *argv[])
{
	try
	{
		if (argc != 4)
			throw std::invalid_argument("not the valid number of arguments (3 required)");
		sys->set_argv(argv);
		manage_files();
	}
	catch (std::invalid_argument &e) 
	{
		std::cerr << "Error : " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
