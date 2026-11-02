/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:34:57 by ricsanto          #+#    #+#             */
/*   Updated: 2026/08/25 11:57:58 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <iostream>

static void printSep(const std::string &label)
{
	std::cout << "\n===== " << label << " =====\n";
}

int main(void)
{
	printSep("INTERN CREATES SHRUBBERY FORM");

	Bureaucrat alice("Alice", 1);
	Intern someIntern;

	try
	{
		AForm *shrubberyForm = someIntern.makeForm("Shrubbery", "garden");
		std::cout << *shrubberyForm << "\n";
		alice.signForm(*shrubberyForm);
		alice.executeForm(*shrubberyForm);
		delete shrubberyForm;
	}
	catch (std::exception &e)
	{
		std::cout << MAGENTA << "	Shouldn't have thrown exception\n" << WHITE;
		std::cout << "Exception: " << e.what() << "\n";
	}
	

	printSep("INTERN CREATES ROBOTOMY FORM");
	try
	{
		AForm *robotomyForm = someIntern.makeForm("Robotomy", "Bender");

		std::cout << *robotomyForm << "\n";
		alice.signForm(*robotomyForm);
		for (int i = 0; i < 4; ++i)
			alice.executeForm(*robotomyForm);
		delete robotomyForm;
	}
	catch (std::exception &e)
	{
		std::cout << MAGENTA << "	Shouldn't have thrown exception\n" << WHITE;
		std::cout << "Exception: " << e.what() << "\n";
	}
	

	printSep("INTERN CREATES PRESIDENTIAL PARDON FORM");
	try
	{
		AForm *pardonForm = someIntern.makeForm("Presidential Pardon", "Ford Prefect");

		std::cout << *pardonForm << "\n";
		alice.signForm(*pardonForm);
		alice.executeForm(*pardonForm);
		delete pardonForm;
	}
	catch(std::exception &e)
	{
		std::cout << MAGENTA << "	Shouldn't have thrown exception in main\n" << WHITE;
		std::cout << "Exception: " << e.what() << "\n";
	}

	
	printSep("INTERN CREATES UNKNOWN FORM");

	try
	{
		AForm *unknownForm = someIntern.makeForm("coffee request", "Bender");
		delete unknownForm;
	}
	catch(std::exception &e)
	{
		std::cout << GREEN  << "	Should have thrown exception\n" << WHITE;
		std::cout << "Exception: " << e.what() << "\n";
	}
	return 0;
}