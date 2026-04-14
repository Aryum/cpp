/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:02:33 by ricsanto          #+#    #+#             */
/*   Updated: 2026/03/02 13:30:39 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/AMateria.hpp"
#include "header/ICharacter.hpp"

// =================== (Cons/Des)tructors ===================

AMateria::AMateria() :
	_type("Hands")
{
	std::cout << YELLOW << "Default Materia created\n" << WHITE;
}

AMateria::AMateria(const AMateria& other) :
	_type(other._type)
{
	std::cout << YELLOW << "Cloned materia ";
	std::cout << WHITE  << _type << "\n";
}

AMateria::AMateria(const std::string& type) :
	_type(type)
{
	std::cout << YELLOW << "Created new materia ";
	std::cout << WHITE  << _type << "\n";
}

AMateria::~AMateria()
{
	std::cout << YELLOW << "Destoyed materia ";
	std::cout << WHITE  << _type << "\n";
}

// =================== Operators ===================

AMateria& AMateria::operator=(const AMateria& other)
{
	if (this != &other)
	{
		std::cout << _type;
		std::cout << YELLOW << " transmuted to ";
		std::cout << WHITE  << other.GetType() << "\n";
		_type = other._type;
	}
	else
	{
		std::cout << _type;
		std::cout << YELLOW << " is already ";
		std::cout << WHITE << other.GetType() << "\n";
	}
	return *this;
}

// =================== Public ===================

const std::string& AMateria::GetType(void) const
{
	return _type;
}

void AMateria::Use(ICharacter& target)
{
	std::cout << "* throws a knuckle sandwich to " << target.GetName() << " *\n";
}