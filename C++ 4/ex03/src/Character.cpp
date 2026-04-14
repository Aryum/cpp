/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:38:44 by ricsanto          #+#    #+#             */
/*   Updated: 2026/03/02 13:30:47 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/Character.hpp"
#include "header/AMateria.hpp"
#include "header/Ground.hpp"

bool Character::_createdGround = false;
Ground *Character::_ground = NULL;
unsigned int Character::_count = 0;

// =================== (Cons/Des)tructors ===================

Character::Character() :
	_name("Unnamed")
{
	std::cout << YELLOW << "Default Character created\n" << WHITE;
	
	_count++;
	if (!_createdGround)
	{
		_ground = new Ground();
		_createdGround = true;
	}
	for (int i = 0; i < INV_SPACE; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character& other) :
	_name(other._name)
{
	std::cout << YELLOW << "Cloned character ";
	std::cout << WHITE  << _name << "\n";

	_count++;
	if (!_createdGround)
	{
		_ground = new Ground();
		_createdGround = true;
	}
	for (int i = 0; i < INV_SPACE; i++)
	{
		if (other._inventory[i] != NULL)
			_inventory[i] = other._inventory[i]->Clone();
		else
			_inventory[i] = NULL;
	}
}

Character::Character(const std::string& name) :
	_name(name)
{
	std::cout << YELLOW << "Created new character ";
	std::cout << WHITE  << _name << "\n";
	
	_count++;
	if (!_createdGround)
	{
		_ground = new Ground();
		_createdGround = true;
	}
	for (int i = 0; i < INV_SPACE; i++)
		_inventory[i] = NULL;
}

Character::~Character()
{
	std::cout << _name;
	std::cout << YELLOW << " was killed in an adventure";
	std::cout << WHITE << "\n";
	for (int i = 0; i < INV_SPACE; i++)
		delete _inventory[i];
	_count--;
	if (_count == 0)
		delete _ground;
}

// =================== Operators ===================

Character& Character::operator=(const Character& other)
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
			else
				_inventory[i] = NULL;
		}
	}
	return *this;
}

// =================== Public ===================

const std::string& Character::GetName(void) const
{
	return _name;
}

void Character::Equip(AMateria *m)
{
	if (m == NULL)
	{
		std::cout << _name << "'s";
		std::cout << RED << " doesnt support void materias\n" << WHITE;
		return ;
	}
	int i = 0;
	while (i < INV_SPACE)
	{
		if (_inventory[i] == NULL)
		{
			std::cout << _name;
			std::cout << BLUE << " equiped ";
			std::cout << WHITE << m->GetType();
			std::cout << BLUE << " in slot ";
			std::cout << WHITE << i << "\n";
			_inventory[i] = m;
			break;
		}
		i++;
	}
	if (i == INV_SPACE)
	{
		std::cout << _name << "'s";
		std::cout << RED << " inventory is full ";
		std::cout << WHITE << m->GetType();
		std::cout << RED << " was left on the ground \n" << WHITE;
		_ground->Add(m);
	}
}

void Character::Unequip(int idx)
{
	if (idx >= INV_SPACE || idx < 0)
	{
		std::cout << _name;
		std::cout << RED << " invalid inventory index ";
		std::cout << WHITE << idx << "\n";
		return ;
	}
	if (_inventory[idx] == NULL)
	{
		std::cout << _name;
		std::cout << RED << " trying to unequip empty slot " ;
		std::cout << WHITE << idx << "\n";
		return ;
	}
	std::cout << _name;
	std::cout << BLUE << " dropped ";
	std::cout << WHITE << _inventory[idx]->GetType() << "\n";
	_ground->Add(_inventory[idx]);
	_inventory[idx] = NULL;
}

void Character::Use(int idx, ICharacter& target)
{
	if (idx >= INV_SPACE || idx < 0)
	{
		std::cout << idx;
		std::cout << RED << " is an invalid inventory index\n" << WHITE ;
		return ;
	}
	if (_inventory[idx] == NULL)
	{
		std::cout << _name;
		std::cout << RED << " inventory slot nbr " << WHITE << idx; 
		std::cout << RED << "is empty\n" << WHITE;
		return ;
	}
	_inventory[idx]->Use(target);
}

