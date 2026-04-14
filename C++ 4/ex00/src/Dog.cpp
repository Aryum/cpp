/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:02:59 by ricsanto          #+#    #+#             */
/*   Updated: 2026/03/02 11:58:15 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/Dog.hpp"

// =================== (Cons/Des)tructors ===================

Dog::Dog() :
	Animal("Dog")
{
	_color = MAGENTA;
	PrintType();
	std::cout << _color << "doing a big stretch" << WHITE;
	std::cout <<  "\n";
}

Dog::Dog(const Dog& other) :
	Animal(other)
{
	_color = MAGENTA;
	PrintType();
	std::cout << _color << "chasing his friends" << WHITE;
	std::cout <<  "\n";
}

Dog::~Dog()
{
	PrintType();
	std::cout << _color << "is chewing a bone" << WHITE;
	std::cout <<  "\n";
}

// =================== Operators ===================

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

void Dog::MakeSound(void) const
{
	PrintType();
	std::cout << _color << "barks" << WHITE;
	std::cout << "\n";
}