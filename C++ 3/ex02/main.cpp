/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:40:02 by ricsanto          #+#    #+#             */
/*   Updated: 2026/01/14 16:42:04 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/FragTrap.hpp"
#include "src/ScavTrap.hpp"

int main()
{
	ClapTrap monkey("guh");
	ScavTrap unamed;
	FragTrap jose("jose");
	FragTrap josejr = FragTrap(jose);
	FragTrap fernando("fernando");

	for (int i = 0; i < 12; i++)
		jose.attack("Alberto");
	std::cout << "\n";
	jose.takeDamage(9);
	monkey.takeDamage(6);
	fernando = jose;
	for (int i = 0; i < 12; i++)
	{
		josejr.beRepaired(1);
		monkey.beRepaired(1);
	}
	std::cout << "\n";
	for (int i = 0; i < 12; i++)
		unamed.takeDamage(1);
	unamed.guardGate();
	std::cout << "\n";
	fernando.takeDamage(15);
	fernando.beRepaired(2);

	std::cout << "\n\n\n\n";
	fernando.beRepaired(2);
	
	fernando.takeDamage(1000);
	fernando.highFivesGuys();

	for (int i = 0; i < 3; i++)
		josejr.highFivesGuys();
}