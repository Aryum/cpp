/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:02:55 by ricsanto          #+#    #+#             */
/*   Updated: 2026/03/02 12:15:23 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/Cat.hpp"

// =================== (Cons/Des)tructors ===================

Cat::Cat() :
	Animal("Cat")
{
	_color = GREEN;
	PrintType();
	std::cout << _color << "is preparing to be mischievous" << WHITE;
	std::cout <<  "\n";
}

Cat::Cat(const Cat& other) :
	Animal(other)
{
	_color = GREEN;
	PrintType();
	std::cout << _color << "is playing with his mates" << WHITE;
	std::cout <<  "\n";
}

Cat::~Cat()
{
	PrintType();
	std::cout << _color << "is drinking some warm milk" << WHITE;
	std::cout <<  "\n";
}

// =================== Operators ===================

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
		Animal::operator=(other);
	return *this;
}
// =================== Public ===================

void Cat::MakeSound(void) const
{
	PrintType();
	std::cout << _color << "meow" << WHITE;
	std::cout << "\n";
}