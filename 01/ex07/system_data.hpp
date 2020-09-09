/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_data.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 09:05:12 by ldutriez          #+#    #+#             */
/*   Updated: 2020/09/09 10:55:32 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYSTEM_DATA_HPP
# define SYSTEM_DATA_HPP

# include <iostream>

class system_data
{
	private:
		std::string 		*_filename;
		std::string 		*_to_replace;
		std::string 		*_replacement;
		std::ifstream		*_input_file;
		std::ofstream		*_output_file;

	public:
// CONSTRUCTORS | DESTRUCTOR

							system_data();
							~system_data();
// ACCESSORS
	// GETTERS

		std::string const	&filename(void) const;
		std::string const	&to_replace(void) const;
		std::string const	&replacement(void) const;
		std::ifstream const	&input_file(void) const;
	//SETTERS

		void				set_argv(char **argv);
		void				set_filename(std::string filename);
		void				set_to_replace(std::string to_replace);
		void				set_replacement(std::string replacement);
		void				set_input_file(std::ifstream file);
		void				set_output_file(std::ofstream file);
};

extern system_data *sys;

#endif