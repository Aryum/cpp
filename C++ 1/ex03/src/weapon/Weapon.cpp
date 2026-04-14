/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 16:17:59 by ricsanto          #+#    #+#             */
/*   Updated: 2026/02/25 10:32:05 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// =================== (Cons/Des)tructors ===================

Weapon::Weapon() : _type("Fist")
{}
Weapon::Weapon(std::string name) : _type(name)
{}
Weapon::Weapon(const Weapon &other) : _type(other._type)
{}

Weapon::~Weapon()
{}

// =================== Operator ===================

Weapon &Weapon::operator=(const Weapon &other)
{
	if (&other != this)
		_type = other._type;
	return *this;
}

// =================== Public ===================

void Weapon::setType(std::string type)
{
	_type = type;
}

const std::string& Weapon::getType(void)
{
	return _type;
}
