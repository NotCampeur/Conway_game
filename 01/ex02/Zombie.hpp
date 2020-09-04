/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 11:37:46 by ldutriez          #+#    #+#             */
/*   Updated: 2020/09/04 15:45:27 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <time.h>

class Zombie
{
	public:
	
		enum ZombieType
		{
			boomer	= 0,
			hunter	= 1,
			smoker	= 2,
			tank	= 3,
			charger	= 4,
			jockey	= 5,
			spitter	= 6,
			witch	= 7,
			basic	= 8
		};
	private:

		ZombieType 	_type;
		std::string	_name;
	public:

// CONSTRUCTORS | DESTRUCTOR
					Zombie();
					Zombie(bool random);
					Zombie(ZombieType type, std::string name);
					~Zombie();

// ACCESSORS
		ZombieType	type(void) const;
		std::string	name(void) const;
		std::string	type_str(void) const;
		
		void		set_type(ZombieType type);
		void		set_name(std::string name);

// METHOD
		void		advert(void) const;
};

#endif