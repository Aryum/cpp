/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 16:18:08 by ricsanto          #+#    #+#             */
/*   Updated: 2026/01/09 12:30:18 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

// =================== (Cons/Des)tructors ===================

HumanB::HumanB() : 
	_name(),
	_weapon(NULL)
{}

HumanB::HumanB(std::string name) : 
	_name(name), 
	_weapon(NULL)
{}

HumanB::HumanB(const HumanB &other) :
	_name(other._name),
	_weapon(other._weapon)
{}
HumanB::~HumanB()
{}

// =================== Operator ===================

HumanB &HumanB::operator=(const HumanB &other)
{
	if (this != &other)
	{
		_name = other._name;
		_weapon = other._weapon;
	}
	return *this;
}

// =================== Public ===================

void HumanB::attack()
{
	std::string weapon;
	if (_weapon != NULL)
		weapon = _weapon->getType();
	else
		weapon = "imagination";
	std::cout << _name << " attacks with their " << weapon << "\n";
}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}