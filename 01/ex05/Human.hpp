/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 14:01:01 by ldutriez          #+#    #+#             */
/*   Updated: 2020/11/03 11:09:17 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

# include "Brain.hpp"

class Human
{
	private:
		const Brain	_brain;

	public:

// CONSTRUCTORS | DESTRUCTOR
				Human();
				~Human();

// GETTER
	const Brain &getBrain(void) const;

//METHOD
	std::string	identify(void) const;
};

#endif