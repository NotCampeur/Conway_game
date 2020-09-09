/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 15:00:25 by ldutriez          #+#    #+#             */
/*   Updated: 2020/09/09 15:51:09 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

# include <iostream>

class Human
{
	private:
		void	meleeAttack(std::string const &target);
		void	rangedAttack(std::string const &target);
		void	intimidatingShout(std::string const &target);

	public:
		void	action(std::string const &action_name, std::string const &target);
};

#endif