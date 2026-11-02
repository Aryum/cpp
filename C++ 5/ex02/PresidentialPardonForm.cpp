/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 15:51:59 by ricsanto          #+#    #+#             */
/*   Updated: 2026/06/16 13:51:55 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// =================== (Cons/Des)tructors ===================

PresidentialPardonForm::PresidentialPardonForm() :
	AForm("Presidential Pardon", "Unknown", 5, 25)
{
	std::cout << YELLOW << "	Someone requested a pardon\n" << WHITE;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm("Presidential Pardon", target, 5, 25)
{
	std::cout << "	" << target << YELLOW << " requested pardon\n" << WHITE;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other):
	AForm("Presidential Pardon", other.getTarget(), 137, 145)
{
	std::cout << "	" << other.getTarget() << YELLOW << " has partners in crime\n" << WHITE;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "	" << getTarget() << YELLOW << " pardon erased\n" << WHITE;
}

// =================== Operators ===================

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (&other != this)
		std::cout << MAGENTA << "Pardons can't be changed\n" << WHITE;
	return *this;
}

// =================== Protected ===================

void PresidentialPardonForm::create(void) const
{
	std::cout << getTarget() << YELLOW << " has been pardoned by Zaphod Beeblebrox\n" << WHITE;
}

