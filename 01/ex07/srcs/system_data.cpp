/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_data.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 09:04:53 by ldutriez          #+#    #+#             */
/*   Updated: 2020/11/04 12:50:32 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system_data.hpp"

// CREATORS | DESTRUCTOR

system_data::system_data()
{
	_filename = new std::string;
	_to_replace = new std::string;
	_replacement = new std::string;
}

system_data::~system_data()
{
	delete _filename;
	delete _to_replace;
	delete _replacement;
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

	// SETTERS

void				system_data::set_argv(char **argv)
{
	_filename->assign(argv[1]);
	_to_replace->assign(argv[2]);
	_replacement->assign(argv[3]);
	if (_filename->size() == 0 || _to_replace->size() == 0 || _replacement->size() == 0)
		throw std::invalid_argument("one of the arguments is empty");
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