/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:13:08 by ricsanto          #+#    #+#             */
/*   Updated: 2026/03/02 13:30:42 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/Cure.hpp"
#include "header/ICharacter.hpp"

// =================== (Cons/Des)tructors ===================

Cure::Cure() :
	AMateria("cure")
{
	std::cout << YELLOW << "Default cure scroll created\n" << WHITE;
}

Cure::Cure(const Cure& other) :
	AMateria(other)
{
	std::cout << YELLOW << "Copied a cure scroll\n" << WHITE;
}

Cure::~Cure()
{
	std::cout << YELLOW << "Cure scroll was teared to pieces\n" << WHITE;
}

// =================== Operators ===================

Cure& Cure::operator=(const Cure& other)
{
	if (this != &other)
		std::cout << MAGENTA << "Cure scrolls are all the same!\n" << WHITE;
	return *this;
}

// =================== Public ===================

AMateria* Cure::Clone(void) const
{
	std::cout << BLUE << "A new cure scroll was created\n" << WHITE;
	return new Cure(*this);
}

void Cure::Use(ICharacter& target)
{
	std::cout << BLUE << "* heals ";
	std::cout << WHITE << target.GetName() << "'s ";
	std::cout << BLUE << "wounds *";
	std::cout << WHITE << "\n";
}