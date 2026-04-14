/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:02:55 by ricsanto          #+#    #+#             */
/*   Updated: 2026/03/02 13:29:51 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/Cat.hpp"

// =================== (Cons/Des)tructors ===================

Cat::Cat() :
	Animal("Cat"),
	_brain(new Brain())
{
	_color = GREEN;
	PrintType();
	std::cout << _color << "is preparing to be mischievous" << WHITE;
	std::cout <<  "\n";
}

Cat::Cat(const Cat& other) :
	Animal(other),
	_brain(new Brain(*other._brain))
{
	_color = GREEN;
	PrintType();
	std::cout << _color << "is playing with his mates" << WHITE;
	std::cout <<  "\n";
}

Cat::~Cat()
{
	PrintType();
	std::cout << BLUE << "is drinking some warm milk" << WHITE;
	std::cout <<  "\n";
	delete _brain;
}

// =================== Operators ===================

Cat& Cat::operator=(const Cat& other)
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

void Cat::MakeSound(void) const
{
	PrintType();
	std::cout << _color << "meow" << WHITE;
	std::cout << "\n";
}

void Cat::Add_Idea(std::string idea)
{
	_brain->Add_Idea(idea);
}

void Cat::Print_Ideas(void) const
{
	PrintType();
	std::cout << "Is thinking about\n";
	_brain->Print_Ideas();
}