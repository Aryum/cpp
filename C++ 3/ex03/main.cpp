/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:40:02 by ricsanto          #+#    #+#             */
/*   Updated: 2026/01/14 16:41:49 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/DiamondTrap.hpp"

int main()
{
	DiamondTrap unamed;
	DiamondTrap jose("jose");
	DiamondTrap josejr = DiamondTrap(jose);
	DiamondTrap fernando("fernando");

	for (int i = 0; i < 12; i++)
		jose.attack("Alberto");
	std::cout << "\n";
	jose.takeDamage(9);
	fernando = jose;
	for (int i = 0; i < 12; i++)
		josejr.beRepaired(1);
	std::cout << "\n";
	for (int i = 0; i < 12; i++)
		unamed.takeDamage(1);
	unamed.guardGate();
	std::cout << "\n";
	fernando.takeDamage(15);
	fernando.beRepaired(2);

	std::cout << "\n\n\n\n";
	fernando.guardGate();
	fernando.highFivesGuys();
	fernando.whoAmI();
}