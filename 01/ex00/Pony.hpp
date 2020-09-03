/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 15:19:32 by ldutriez          #+#    #+#             */
/*   Updated: 2020/09/03 16:41:01 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

#include <iostream>

class Pony
{
    private:

        unsigned char   _legs_nbr;
        unsigned char   _eyes_nbr;
        unsigned char   _mph;
    public:
//CREATORS | DESTRUCTOR
                        Pony();
                        Pony(int legs_nbr,int eyes_nbr = 0, int mph = 0);
                        ~Pony();

//ACCESSORS
        void            set_legs_nbr(int nbr);
        void            set_eyes_nbr(int nbr);
        void            set_mph(int nbr);

        unsigned char   legs_nbr(void) const;
        unsigned char   eyes_nbr(void) const;
        unsigned char   mph(void) const;

//METHOD
        void            to_graze(void) const;
        void            to_mine(void) const;

        void            print(void) const;
};

void                    ponyOnTheStack(int legs_nbr = 0,int eyes_nbr = 0, int mph = 0);
Pony                    *ponyOnTheHeap(int legs_nbr = 0,int eyes_nbr = 0, int mph = 0);

#endif