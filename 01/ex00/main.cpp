/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 15:13:47 by ldutriez          #+#    #+#             */
/*   Updated: 2020/09/03 16:47:15 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void    ponyOnTheStack(int legs_nbr, int eyes_nbr, int mph)
{
    Pony    stackPony(legs_nbr, eyes_nbr, mph);

    stackPony.to_graze();
    stackPony.print();
}

Pony    *ponyOnTheHeap(int legs_nbr, int eyes_nbr, int mph)
{
    Pony    *heapPony;

    heapPony = new Pony(legs_nbr, eyes_nbr, mph);
    heapPony->to_mine();
    heapPony->print();
    return heapPony;
}

int     main(void)
{
    Pony    *cyberPony;
    
    cyberPony = ponyOnTheHeap(86, 134, 89025);
    ponyOnTheStack(86, 134, 89025);
    std::cout << "The heap Pony still alive!!" << std::endl;
    system("wait 2000");
    delete cyberPony;
    std::cout << "heap Pony has been deleted, LEAKS ARE NOT ACCEPTED" << std::endl;
    return 0;
}