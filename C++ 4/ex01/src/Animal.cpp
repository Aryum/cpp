/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:02:50 by ricsanto          #+#    #+#             */
/*   Updated: 2026/01/16 17:12:20 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/Animal.hpp"

// =================== (Cons/Des)tructors ===================

Animal::Animal() :
	_type("Undefined"),
	_color(YELLOW)
{
	PrintType();
	std::cout << _color << "creature was raised in a laboratory" << WHITE;
	std::cout << "\n";
}
Animal::Animal(std::string type) :
	_type(type),
	_color(YELLOW)
{
	PrintType();
	std::cout << _color << "animal was spawned" << WHITE;
	std::cout << "\n";
}
Animal::Animal(const Animal& other) :
	_type(other._type),
	_color(YELLOW)
{
	PrintType();
	std::cout << _color << "created another one" << WHITE;
	std::cout << "\n";
}
Animal::~Animal()
{
	PrintType();
	std::cout << RED << "is taking a nap" << WHITE;
	std::cout << "\n";
}

// =================== Operators ===================

Animal& Animal::operator=(const Animal& other)
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

void Animal::MakeSound(void) const
{
	PrintType();
	std::cout << _color << "make unrecognisable sound" << WHITE;
	std::cout << "\n";
}

std::string Animal::GetType(void) const
{
	return _type;
}

// =================== Protected ===================

void Animal::PrintType(void) const
{
	std::cout << "[" << _type << "] ";
}