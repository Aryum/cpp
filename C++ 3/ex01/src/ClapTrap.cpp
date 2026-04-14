/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:43:11 by ricsanto          #+#    #+#             */
/*   Updated: 2026/01/14 15:46:47 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// =================== (Cons/Des)tructors ===================

ClapTrap::ClapTrap() :
	_base_Name("Unamed"),
	_type("Clap"),
	_hit_Points(10),
	_energy_Points(10),
	_attack_Points(0)
{
	std::cout << YELLOW << _type << "Trap Default constructor called\n" << WHITE;
}

ClapTrap::ClapTrap(std::string name) :
	_base_Name(name),
	_type("Clap"),
	_hit_Points(10),
	_energy_Points(10),
	_attack_Points(0)
{
	std::cout << _base_Name << " " << YELLOW << _type << "Trap was born\n" << WHITE;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap) :
	_base_Name(clapTrap._base_Name),
	_type("Clap"),
	_hit_Points(clapTrap._hit_Points),
	_energy_Points(clapTrap._energy_Points),
	_attack_Points(clapTrap._attack_Points)
{
	std::cout << _base_Name << " " << YELLOW << _type << "Trap was cloned\n" << WHITE;
}

ClapTrap::~ClapTrap()
{
	std::cout << _base_Name << " " << RED << _type << "Trap exploded\n" << WHITE;
}

// =================== Operators ===================

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
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

void ClapTrap::attack(const std::string& target)
{
	if (_hit_Points > 0 && _energy_Points > 0)
	{
		std::cout << RED << _type << "Trap " << WHITE << _base_Name;
		std::cout << RED << " attacks " << WHITE << target;
		std::cout << RED << " causing " << WHITE << _attack_Points;
		std::cout << RED << " points of damage" << WHITE;
		std::cout << "\n";
		_energy_Points--;
	}
	else
	{
		std::cout << _base_Name << " ";
		std::cout << BLUE << _type << "Trap";
		if (_hit_Points == 0)
			std::cout << "is dead and can't attack";
		else
			std::cout << " is out of energy and can't attack";
		std::cout  << WHITE << "\n";
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_Points == 0)
	{
		std::cout << _base_Name << " ";
		std::cout << BLUE << _type << "Trap is already dead" << WHITE;
		std::cout << "\n";
		return ;
	}
	_hit_Points = amount > _hit_Points ? 0 : _hit_Points - amount;
	std::cout << MAGENTA << _type << "Trap " << WHITE << _base_Name;
	std::cout << MAGENTA << " takes " << WHITE << amount;
	std::cout << MAGENTA << " points of damage" << WHITE << " ";
	std::cout << _hit_Points << " current";
	std::cout << "\n";
	if (_hit_Points == 0)
	{
		std::cout << _base_Name << " ";
		std::cout << BLUE << _type << "Trap has fallen in battle" << WHITE;
		std::cout << "\n";
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy_Points > 0)
	{
		if (_hit_Points == 0)
		{
			std::cout << _base_Name;
			std::cout << BLUE << " " << _type << "Trap came back to life" << WHITE;
			std::cout << "\n";
		}
		_energy_Points--;
		_hit_Points += amount;
		std::cout << GREEN << _type << "Trap " << WHITE << _base_Name;
		std::cout << GREEN << " is being repaired for " <<  WHITE << amount;
		std::cout << GREEN << " points" << WHITE << " ";
		std::cout << _hit_Points << " current";
		std::cout << "\n";
	}
	else
	{
		std::cout << _base_Name;
		std::cout << BLUE << " " << _type << "Trap is out of energy and can't repair himself" << WHITE;
		std::cout << "\n";
	}
}
