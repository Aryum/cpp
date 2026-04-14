/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:12:06 by ricsanto          #+#    #+#             */
/*   Updated: 2026/03/11 15:59:40 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// =================== (Cons/Des)tructors ===================

DiamondTrap::DiamondTrap() :
	_name("Unamed_clap_name")
{
	_type = "Diamond";
	_hit_Points = FragTrap::_hit_Points;
	_energy_Points = ScavTrap::_energy_Points;
	_attack_Points = FragTrap::_attack_Points;
	std::cout << YELLOW << "	Basic Diamondtrap created\n" << WHITE;
}
DiamondTrap::DiamondTrap(std::string name) : 
	ClapTrap(name + "_clap_name"),
	ScavTrap(name + "_clap_name"),
	FragTrap(name + "_clap_name"),
	_name(name)
{
	_type = "Diamond";
	_hit_Points = FragTrap::_hit_Points;
	_energy_Points = ScavTrap::_energy_Points;
	_attack_Points = FragTrap::_attack_Points;
	std::cout << "	" << _base_Name << YELLOW << " ascended to Diamondtrap\n" << WHITE;

}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap) : 
	ClapTrap(diamondTrap),
	ScavTrap(diamondTrap),
	FragTrap(diamondTrap),
	_name(diamondTrap._name)
{
	_type = "Diamond";
	_hit_Points = diamondTrap._hit_Points;
	_energy_Points = diamondTrap._energy_Points;
	_attack_Points = diamondTrap._attack_Points;
	std::cout << "	" << _base_Name << YELLOW << " took some parts from another Diamondtrap\n" << WHITE;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "	"<< _base_Name << RED  << " needs some vacation\n" << WHITE;
}

// =================== Operators ===================

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		std::cout << YELLOW << _type <<  "Trap " << WHITE << _base_Name;
		std::cout << YELLOW << " copied " << WHITE << other._base_Name;
		std::cout << YELLOW << " what lack of originality\n" << WHITE;
		_base_Name = other._base_Name;
		_name = other._name;
		
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

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
		
	std::cout << "Frag " << FragTrap::_hit_Points << " Diamond " << _hit_Points;
	
	std::cout << BLUE << _type << "Trap to be " << WHITE << _base_Name;
	std::cout << BLUE << " or not to be " << WHITE << _name;
	std::cout << BLUE << " that's the question";
	std::cout << WHITE << "\n";
}