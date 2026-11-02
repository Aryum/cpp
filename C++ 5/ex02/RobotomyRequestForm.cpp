/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 15:51:59 by ricsanto          #+#    #+#             */
/*   Updated: 2026/06/16 13:08:08 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// =================== (Cons/Des)tructors ===================

RobotomyRequestForm::RobotomyRequestForm() :
	AForm("Robotomy", "Unknown", 45, 72)
{
	std::cout << YELLOW << "	Someone requested robotomy\n" << WHITE;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm("Robotomy", target, 45, 72)
{
	std::cout << "	" << target << YELLOW << " requested robotomy\n" << WHITE;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other):
	AForm("Robotomy", other.getTarget(), 137, 145)
{
	std::cout << "	" << other.getTarget() << YELLOW << " needs to be creative\n" << WHITE;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "	" << getTarget() << YELLOW << " robotomy tools returned\n" << WHITE;
}

// =================== Operators ===================

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (&other != this)
		std::cout << MAGENTA << "Robotomy forms cannot be modified\n" << WHITE;
	return *this;
}

// =================== Protected ===================

void RobotomyRequestForm::create(void) const
{
	std::cout << YELLOW << "*INSERT DRILLING NOISES*\n	" << WHITE;
	if (rand() % 2)
		std::cout << getTarget() << GREEN << " has been robotomized\n" << WHITE;
	else
		std::cout << getTarget() << GREEN << " is still a fleshling\n" << WHITE;
}

