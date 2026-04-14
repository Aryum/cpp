/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:02:55 by ricsanto          #+#    #+#             */
/*   Updated: 2026/01/16 13:57:30 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/WrongCat.hpp"

// =================== (Cons/Des)tructors ===================

WrongCat::WrongCat() :
	Animal("WrongCat")
{
	_color = GREEN;
	PrintType();
	std::cout << _color << "is preparing to be mischievous" << WHITE;
	std::cout <<  "\n";
}

WrongCat::WrongCat(const WrongCat& other) :
	Animal(other)
{
	_color = GREEN;
	PrintType();
	std::cout << _color << "is playing with his mates" << WHITE;
	std::cout <<  "\n";
}

WrongCat::~WrongCat()
{
	PrintType();
	std::cout << _color << "is drinking some warm milk" << WHITE;
	std::cout <<  "\n";
}

// =================== Operators ===================

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
		Animal::operator=(other);
	return *this;
}
// =================== Public ===================

void WrongCat::MakeSound(void) const
{
	PrintType();
	std::cout << _color << "meow" << WHITE;
	std::cout << "\n";
}