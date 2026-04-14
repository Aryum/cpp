/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:12:06 by ricsanto          #+#    #+#             */
/*   Updated: 2026/01/14 15:46:47 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// =================== (Cons/Des)tructors ===================

FragTrap::FragTrap()
{
	_type = "Frag";
	_hit_Points = 100;
	_energy_Points = 100;
	_attack_Points = 30;
	std::cout << YELLOW << "	Basic Fragtrap created\n" << WHITE;
}
FragTrap::FragTrap(std::string name) : 
	ClapTrap(name)
{
	_type = "Frag";
	_hit_Points = 100;
	_energy_Points = 100;
	_attack_Points = 30;
	std::cout << "	" << _base_Name << YELLOW << " upgraded to Fragtrap\n" << WHITE;

}

FragTrap::FragTrap(const FragTrap& fragTrap) : 
	ClapTrap(fragTrap)
{
	_type = "Frag";
	_hit_Points = 100;
	_energy_Points = 100;
	_attack_Points = 30;
	std::cout << "	" << _base_Name << YELLOW << " mutated to a Fragtrap\n" << WHITE;
}

FragTrap::~FragTrap()
{
	std::cout << "	"<< _base_Name << RED  << " doesn't look so good\n" << WHITE;
}

// =================== Operators ===================

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		std::cout << YELLOW << _type <<  "Trap " << WHITE << _base_Name;
		std::cout << YELLOW << " copied " << WHITE << other._base_Name;
		std::cout << YELLOW << " what lack of originality\n" << WHITE;
		_base_Name = other._base_Name;

		std::cout << YELLOW << "	health	" << WHITE << _hit_Points;
		std::cout << YELLOW << "	->	" << WHITE << other._hit_Points;
		std::cout << "\n";
		_hit_Points = other._hit_Points;

		std::cout << YELLOW << "	energy	" << WHITE << _energy_Points;
		std::cout << YELLOW << "	->	" << WHITE << other._energy_Points;
		std::cout << "\n";
		_energy_Points = other._energy_Points;
		
		std::cout << YELLOW << "	attack	" << WHITE << _attack_Points ;
		std::cout << YELLOW << "	->	" << WHITE << other._attack_Points;
		std::cout << "\n";
		_attack_Points = other._attack_Points;
	}
	return *this;
}

// =================== Public ===================

void FragTrap::highFivesGuys(void)
{

	if (_hit_Points == 0)
	{
		std::cout << _base_Name << " ";
		std::cout << RED << _type << "Trap ";
		std::cout << "died and cannot be a good robot";
	}
	else
	{
		std::cout << BLUE << _type << "Trap " << WHITE << _base_Name;
		std::cout << BLUE << " is standing his hand awkwardly waiting for an high five";
	}
	std::cout << WHITE << "\n";
}
