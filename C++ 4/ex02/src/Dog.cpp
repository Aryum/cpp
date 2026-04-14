/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:02:59 by ricsanto          #+#    #+#             */
/*   Updated: 2026/03/02 13:29:47 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/Dog.hpp"

// =================== (Cons/Des)tructors ===================

Dog::Dog() :
	Animal("Dog"),
	_brain(new Brain())
{
	_color = MAGENTA;
	PrintType();
	std::cout << _color << "doing a big stretch" << WHITE;
	std::cout <<  "\n";
}

Dog::Dog(const Dog& other) :
	Animal(other),
	_brain(new Brain(*other._brain))
{
	_color = MAGENTA;
	PrintType();
	std::cout << _color << "chasing his friends" << WHITE;
	std::cout <<  "\n";
}

Dog::~Dog()
{
	PrintType();
	std::cout << YELLOW << "is chewing a bone" << WHITE;
	std::cout <<  "\n";
	delete _brain;
}

// =================== Operators ===================

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete _brain;
		_brain = other._brain;
	}
	return *this;
}

// =================== Public ===================

void Dog::MakeSound(void) const
{
	PrintType();
	std::cout << _color << "barks" << WHITE;
	std::cout << "\n";
}

void Dog::Add_Idea(std::string idea)
{
	_brain->Add_Idea(idea);
}

void Dog::Print_Ideas(void) const
{
	PrintType();
	std::cout << "Is thinking about\n	";
	_brain->Print_Ideas();
}