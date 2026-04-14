/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 13:29:28 by ricsanto          #+#    #+#             */
/*   Updated: 2026/03/02 13:29:30 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/WrongAnimal.hpp"

// =================== (Cons/Des)tructors ===================

WrongAnimal::WrongAnimal() :
	_type("Wrong Undefined"),
	_color(YELLOW)
{
	PrintType();
	std::cout << _color << "creature was raised in a laboratory" << WHITE;
	std::cout << "\n";
}
WrongAnimal::WrongAnimal(std::string type) :
	_type(type),
	_color(YELLOW)
{
	PrintType();
	std::cout << _color << "animal was spawned" << WHITE;
	std::cout << "\n";
}
WrongAnimal::WrongAnimal(const WrongAnimal& other) :
	_type(other._type),
	_color(YELLOW)
{
	PrintType();
	std::cout << _color << "created another one" << WHITE;
	std::cout << "\n";
}
WrongAnimal::~WrongAnimal()
{
	PrintType();
	std::cout << _color << "is taking a nap" << WHITE;
	std::cout << "\n";
}

// =================== Operators ===================

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if(this != &other)
	{
		PrintType();
		std::cout << _color << "transformed into " << WHITE;
		_type = other._type;
		_color = other._color;
		PrintType();
		std::cout << "\n";
	}
	return *this;
}

// =================== Public ===================

void WrongAnimal::MakeSound(void) const
{
	PrintType();
	std::cout << _color << "make unrecognisable sound" << WHITE;
	std::cout << "\n";
}

std::string WrongAnimal::GetType(void) const
{
	return _type;
}

// =================== Protected ===================

void WrongAnimal::PrintType(void) const
{
	std::cout << "[" << _type << "] ";
}