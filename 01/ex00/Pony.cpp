/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 15:43:28 by ldutriez          #+#    #+#             */
/*   Updated: 2020/09/03 16:50:58 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

                Pony::Pony()
{
    _legs_nbr = 0; 
    _eyes_nbr = 0; 
    _mph = 0; 
}

                Pony::Pony(int legs_nbr,int eyes_nbr, int mph)
{
    set_legs_nbr(legs_nbr);
    set_eyes_nbr(eyes_nbr);
    set_mph(mph);
}

                Pony::~Pony()
{
    ;
}

void            Pony::set_legs_nbr(int nbr)
{
    if (nbr < 0)
        nbr = 0;
    if (nbr > 255)
        nbr = 255;
    _legs_nbr = (unsigned char)nbr;
}

void            Pony::set_eyes_nbr(int nbr)
{
    if (nbr < 0)
        nbr = 0;
    if (nbr > 255)
        nbr = 255;
    _eyes_nbr = (unsigned char)nbr;
}

void            Pony::set_mph(int nbr)
{
    if (nbr < 0)
        nbr = 0;
    if (nbr > 255)
        nbr = 255;
    _legs_nbr = (unsigned char)nbr;
}

unsigned char   Pony::legs_nbr(void) const
{
    return _legs_nbr;
}

unsigned char   Pony::eyes_nbr(void) const
{
    return _eyes_nbr;
}

unsigned char   Pony::mph(void) const
{
    return _mph;
}

void            Pony::to_graze(void) const
{
    int     amount_grazed(0);
    
    amount_grazed = _legs_nbr * _eyes_nbr * _mph;
    std::cout << "The Pony graze the hay peacefully from the stack" << std::endl;
    std::cout << (int)amount_grazed << " hay bales have been eaten" << std::endl;
}

void            Pony::to_mine(void) const
{
    int     amount_mined(0);
    
    amount_mined = _legs_nbr * _eyes_nbr * _mph;
    std::cout << "The pony is mining bitcoin from the heap" << std::endl;
    std::cout << (int)amount_mined << " bitcoin have been mined" << std::endl;
}

void            Pony::print(void) const
{
    std::cout << "The pony have : " << (int)_legs_nbr << " legs" << std::endl;
    std::cout << "The pony have : " << (int)_eyes_nbr << " eyes" << std::endl;
    std::cout << "The pony can go up to : " << (int)_mph << " mph" << std::endl << std::endl;
}