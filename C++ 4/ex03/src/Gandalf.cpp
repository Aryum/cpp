/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gandalf.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 13:30:50 by ricsanto          #+#    #+#             */
/*   Updated: 2026/03/02 13:30:55 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/Gandalf.hpp"
#include "header/AMateria.hpp"
#include "header/Ground.hpp"
#include "header/Ice.hpp"

// =================== (Cons/Des)tructors ===================

Gandalf::Gandalf() :
	_name("Gandalf")
{
	std::cout << YELLOW << "Default Gandalf created\n" << WHITE;
	
	for (int i = 0; i < INV_SPACE; i++)
		_inventory[i] = NULL;
	_inventory[0] = new Ice();
}

Gandalf::Gandalf(const Gandalf& other) :
	_name(other._name)
{
	std::cout << YELLOW << "Cloned Gandalf ";
	std::cout << WHITE  << _name << "\n";

	_inventory[0] = other._inventory[0]->Clone();
}

Gandalf::~Gandalf()
{
	std::cout << _name;
	std::cout << YELLOW << " was killed in an adventure";
	std::cout << WHITE << "\n";
	for (int i = 0; i < INV_SPACE; i++)
		delete _inventory[i];
}

// =================== Operators ===================

Gandalf& Gandalf::operator=(const Gandalf& other)
{
	if (&other != this)
	{
		std::cout << _name;
		std::cout << YELLOW << " transmuted to ";
		std::cout << WHITE  << other.GetName() << "\n";
		_name = other._name;
		for (int i = 0; i < INV_SPACE; i++)
		{
			delete _inventory[i];
			if (other._inventory[i] != NULL)
				_inventory[i] = other._inventory[i]->Clone();
		}
	}
	return *this;
}

// =================== Public ===================

const std::string& Gandalf::GetName(void) const
{
	return _name;
}

void Gandalf::Equip(AMateria *m)
{
	(void)m;
	std::cout << RED << "Gandalf has no needs for other tools\n" << WHITE;
}

void Gandalf::Unequip(int idx)
{
	(void)idx;
	std::cout << RED << "Gandalf loves his staff way too much, and wont drop it\n" << WHITE;
}

void Gandalf::Use(int idx, ICharacter& target)
{
	(void)idx;
	_inventory[0]->Use(target);
}

