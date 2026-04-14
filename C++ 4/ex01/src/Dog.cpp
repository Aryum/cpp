/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:02:59 by ricsanto          #+#    #+#             */
/*   Updated: 2026/03/02 12:49:36 by ricsanto         ###   ########.fr       */
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
	if (_brain != NULL)
		_brain->Add_Idea(idea);
	else
	{
		PrintType();
		std::cout << RED << " brain could not be found and can't add thoughts\n";
	}
}

void Dog::Print_Ideas(void) const
{
	PrintType();
	if (_brain != NULL)
	{
		std::cout << YELLOW << "Is thinking about\n" << WHITE;
		_brain->Print_Ideas();
	}
	else
		std::cout << RED << " brain could not be found and doesn't have any thoughts\n";
}