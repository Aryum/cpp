/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 16:18:15 by ricsanto          #+#    #+#             */
/*   Updated: 2026/01/09 12:29:33 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// =================== (Cons/Des)tructors ===================

HumanA::HumanA(std::string name, Weapon& weapon) : 
	_name(name),
	_weapon(weapon)
{}

HumanA::HumanA(const HumanA &other) :
	_name(other._name),
	_weapon(other._weapon)
{}
HumanA::~HumanA()
{}

// =================== Operators ===================

HumanA &HumanA::operator=(const HumanA &other)
{
	if (this != &other)
	{
		_name = other._name;
		_weapon = other._weapon;
	}
	return *this;
}

// =================== Public ===================

void HumanA::attack()
{
	std::cout << _name << " attacks with their " << _weapon.getType() << "\n";
}