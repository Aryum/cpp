/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:12:06 by ricsanto          #+#    #+#             */
/*   Updated: 2026/01/14 15:46:47 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// =================== (Cons/Des)tructors ===================

ScavTrap::ScavTrap() :
	_isGuarding(false)
{
	_type = "Scav";
	_hit_Points = 100;
	_energy_Points = 50;
	_attack_Points = 20;
	std::cout << YELLOW << "	Basic Scavtrap created\n" << WHITE;
}
ScavTrap::ScavTrap(std::string name) : 
	ClapTrap(name),
	_isGuarding(false)
{
	_type = "Scav";
	_hit_Points = 100;
	_energy_Points = 50;
	_attack_Points = 20;
	std::cout << "	" << _base_Name << YELLOW << " evolved to Scavtrap\n" << WHITE;

}

ScavTrap::ScavTrap(const ScavTrap& scavTrap) : 
	ClapTrap(scavTrap),
	_isGuarding(false)
{
	_type = "Scav";
	_hit_Points = 100;
	_energy_Points = 50;
	_attack_Points = 20;
	std::cout << "	" << _base_Name << YELLOW << " took some lessons and is now a Scavtrap\n" << WHITE;
}

ScavTrap::~ScavTrap()
{
	std::cout << "	"<< _base_Name << RED  << " smells like smoke\n" << WHITE;
}

// =================== Operators ===================

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
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

void ScavTrap::guardGate(void)
{
	if (_hit_Points > 0 && _energy_Points > 0)
	{
		_isGuarding = !_isGuarding;
		std::string mode;
		std::cout << BLUE << _type << "Trap " << WHITE << _base_Name;
		std::cout << BLUE << " guard mode " << WHITE;
		std::cout << (_isGuarding ? "ON" : "OFF");
		std::cout << "\n";
		_energy_Points--;
	}
	else
	{
		std::cout << _base_Name << " ";
		std::cout << RED << _type << "Trap ";
		if (_hit_Points == 0)
			std::cout << "died and can't guard";
		else
			std::cout << "requires energy to guard";
		std::cout << WHITE << "\n";
	}
}
