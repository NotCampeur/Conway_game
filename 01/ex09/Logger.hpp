/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 11:29:30 by ldutriez          #+#    #+#             */
/*   Updated: 2020/11/05 13:59:37 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <ctime>

class Logger
{
	private:
	
		std::string	_file_name;
		
		void		logToConsole(std::string message);
		void		logToFile(std::string message);
		std::string	makeLogEntry(std::string message);
	public:

					Logger();
					Logger(std::string file_name);
					~Logger();
					
		void		log(std::string const &dest, std::string const &message);
};

#endif