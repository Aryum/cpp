/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:40:02 by ricsanto          #+#    #+#             */
/*   Updated: 2026/02/25 14:33:34 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/ClapTrap.hpp"

int main()
{
	ClapTrap unamed;
	ClapTrap jose("jose");
	ClapTrap josejr = ClapTrap(jose);
	ClapTrap fernando;
	fernando = ClapTrap("fernando");


	for (int i = 0; i < 12; i++)
		jose.attack("Alberto");
	std::cout << "\n";
	josejr.takeDamage(9);
	fernando = josejr;
	for (int i = 0; i < 12; i++)
		josejr.beRepaired(1);
	std::cout << "\n";
	for (int i = 0; i < 12; i++)
		unamed.takeDamage(1);
	std::cout << "\n";
	fernando.takeDamage(15);
	fernando.beRepaired(2);


}