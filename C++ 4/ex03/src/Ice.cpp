/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:32:42 by ricsanto          #+#    #+#             */
/*   Updated: 2026/03/02 13:31:00 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/Ice.hpp"
#include "header/ICharacter.hpp"

// =================== (Cons/Des)tructors ===================

Ice::Ice() : 
	AMateria("ice") 
{
	std::cout << YELLOW << "Default ice staff created\n" << WHITE;
}

Ice::Ice(const Ice& other) : 
	AMateria(other) 
{
	std::cout << YELLOW << "Replicated an ice staff\n" << WHITE;
}

Ice::~Ice()
{
	std::cout << YELLOW << "Ice staff was broken in half\n" << WHITE;
}

// =================== Operators ===================

Ice& Ice::operator=(const Ice& other)
{
	if (this != &other)
		std::cout << MAGENTA << "Ice staffs are all equal!\n" << WHITE;
	return *this;
}

// =================== Public ===================

AMateria* Ice::Clone(void) const
{
	std::cout << BLUE << "A new ice staff was created\n" << WHITE;
	return new Ice(*this);
}

void Ice::Use(ICharacter& target)
{
	std::cout << BLUE << "* shoots an ice bolt at ";
	std::cout << WHITE << target.GetName();
	std::cout << BLUE << " *\n" << WHITE;
}