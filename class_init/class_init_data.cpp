/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_init_data.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 13:46:53 by ldutriez          #+#    #+#             */
/*   Updated: 2020/09/17 20:43:02 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class_init_data.hpp"

using namespace std;

// CONSTRUCTORS | DESTRUCTOR

                c_class_init_data::c_class_init_data() : _path() , _header_file(), _source_file(1), _class_name()
{
    _type_spacing = 0;
    _var_spacing = 0;
    _class_scope_start = 0;
    _class_scope_end = 0;
	_var_info = NULL;
}

                c_class_init_data::~c_class_init_data()
{
	for (int i(0); _var_info[i] != NULL; i++)
	{
		delete[] _var_info[i];
		_var_info[i] = NULL;
	}
	delete[] _var_info;
}

// ACCESSORS
    // GETTERS

string		  c_class_init_data::path(void) const
{
	return _path;
}

vector<string>  c_class_init_data::header_file(void) const
{
	return _header_file;
}

vector<string>  c_class_init_data::source_file(void) const
{
	return _source_file;
}

string			**c_class_init_data::var_info(void) const
{
	return _var_info;
}

string		  c_class_init_data::class_name(void) const
{
	return _class_name;
}

int			  c_class_init_data::type_spacing(void) const
{
	return _type_spacing;
}

int			  c_class_init_data::var_spacing(void) const
{
	return _var_spacing;
}

int			  c_class_init_data::class_scope_start(void) const
{
	return _class_scope_start;
}

int			  c_class_init_data::class_scope_end(void) const
{
	return _class_scope_end;
}

	// SETTERS

void			c_class_init_data::set_path(string path)
{
	_path = path;
}

void			c_class_init_data::set_header_file(vector<string> header_file)
{
	_header_file = header_file;
}

void			c_class_init_data::set_source_file(vector<string> source_file)
{
	_source_file = source_file;
}

void			c_class_init_data::set_var_info(string **tab)
{
	_var_info = tab;
}

void			c_class_init_data::emplace_header_file(int pos, string new_str)
{
	_header_file.emplace(_header_file.begin() + pos, new_str);
}

void			c_class_init_data::emplace_source_file(int pos, string new_str)
{
	_source_file.emplace(_source_file.begin() + pos, new_str);
}

void			c_class_init_data::set_class_name(string class_name)
{
	_class_name = class_name;
}

void			c_class_init_data::set_type_spacing(int nbr)
{
	_type_spacing = nbr;
}

void			c_class_init_data::set_var_spacing(int nbr)
{
	_var_spacing = nbr;
}

void			c_class_init_data::set_class_scope_start(int line)
{
	_class_scope_start = line;
}

void			c_class_init_data::set_class_scope_end(int line)
{
	_class_scope_end = line;
}

	// PRINTERS

void			c_class_init_data::print_path() const
{
		cout << _path << endl;
}

void			c_class_init_data::print_header_file() const
{
	for (unsigned long i(0); i < _header_file.size(); i++)
		cout << _header_file[i] << endl;
}

void			c_class_init_data::print_source_file() const
{
	for (unsigned long i(0); i < _source_file.size(); i++)
		cout << _source_file[i] << endl;
}

void			c_class_init_data::print_var_info() const
{
	for (size_t i = 0; _var_info[i] != NULL; i++)
	{
		for (size_t j = 0; j < 2; j++)
		{
			cout << _var_info[i][j] << endl;
		}
		cout << endl;
	}

}

void			c_class_init_data::print_class_name() const
{
		cout << _class_name << endl;
}

void			c_class_init_data::print_type_spacing(void) const
{
		cout << _type_spacing << endl;
}

void			c_class_init_data::print_var_spacing(void) const
{
		cout << _var_spacing << endl;
}

void			c_class_init_data::print_class_scope_start() const
{
	cout << _class_scope_start << endl;
}

void			c_class_init_data::print_class_scope_end() const
{
	cout << _class_scope_end << endl;
}