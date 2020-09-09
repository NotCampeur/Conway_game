/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_data.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 09:04:53 by ldutriez          #+#    #+#             */
/*   Updated: 2020/09/09 10:56:48 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replacer.hpp"

// CREATORS | DESTRUCTOR

system_data::system_data()
{
	_filename = new std::string;
	_to_replace = new std::string;
	_replacement = new std::string;
	_input_file = new std::ifstream;
	_output_file = new std::ofstream;
}

system_data::~system_data()
{
	delete _filename;
	delete _to_replace;
	delete _replacement;
	delete _input_file;
	delete _output_file;
}

// ACCESSORS
	// GETTERS

std::string const	&system_data::filename(void) const
{
	return *_filename;
}

std::string const	&system_data::to_replace(void) const
{
	return *_to_replace;
}

std::string const	&system_data::replacement(void) const
{
	return *_replacement;
}

std::ifstream const	&system_data::input_file(void) const
{
	return *_input_file;
}

	// SETTERS

void				system_data::set_argv(char **argv)
{
	_filename->assign(argv[1]);
	_to_replace->assign(argv[2]);
	_replacement->assign(argv[3]);
}

void				system_data::set_filename(std::string filename)
{
	_filename->assign(filename);
}

void				system_data::set_to_replace(std::string to_replace)
{
	_to_replace->assign(to_replace);
}

void				system_data::set_replacement(std::string replacement)
{
	_replacement->assign(replacement);
}

void				system_data::set_input_file(std::ifstream file)
{
	_input_file = &file;
}

void				system_data::set_output_file(std::ofstream file)
{
	_output_file = &file;
}