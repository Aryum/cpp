/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:22:19 by ricsanto          #+#    #+#             */
/*   Updated: 2026/08/27 15:46:09 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// =================== (Cons/Des)tructors ===================

Intern::Intern()
{
	std::cout << YELLOW << "Default Intern created\n" << WHITE;
}

Intern::Intern(const Intern &other)
{
	(void)other;
	std::cout << YELLOW << "Intern duplicated (they are all the same)\n" << WHITE;
}

Intern::~Intern()
{
	std::cout << YELLOW << "Intern discarted\n" << WHITE;
	
}
// =================== Operators ===================

Intern& Intern::operator=(const Intern &other)
{
	if (&other != this)
		std::cout << YELLOW << "Intern tried to copy another one\n" << WHITE;
	return (*this);
}

// =================== Public ===================

AForm* Intern::makeForm(const std::string name, const std::string target)
{
	FormEntry entries[] =
	{	{"Presidential Pardon", generateForm<PresidentialPardonForm>}, 
		{"Robotomy", generateForm<RobotomyRequestForm>}, 
		"Shrubbery", generateForm<ShrubberyCreationForm>};

	for (int i = 0; i < 3; i++)
	{
		if (entries[i].name == name)
			return entries[i].func(name, target);
	}
	throw Intern::InvalidFormException();
	return NULL;
}

// =================== Helper ===================

template <class T>
AForm*	generateForm(const std::string name,const  std::string target)
{
	std::cout << YELLOW << "Intern creates " << WHITE << name << "\n";
	return new T(target);
}

const char *Intern::InvalidFormException::what() const throw()
{
	return "Not a valid Form";
};