/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 12:15:33 by ricsanto          #+#    #+#             */
/*   Updated: 2026/06/16 13:07:12 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

static void printSep(const std::string &label)
{
	std::cout << "\n===== " << label << " =====\n";
}

int main(void)
{
	srand(time(0));
	printSep("SHRUBBERY CREATION FORM");

	Bureaucrat bob("Bob", 140);
	Bureaucrat carol("Carol", 1);
	ShrubberyCreationForm shrubberyForm("garden");

	std::cout << shrubberyForm << "\n";
	std::cout << bob << "\n";
	std::cout << carol << "\n";
	bob.executeForm(shrubberyForm);
	bob.signForm(shrubberyForm);
	bob.executeForm(shrubberyForm);
	carol.executeForm(shrubberyForm);

	std::cout <<"\n";
	printSep("ROBOTOMY REQUEST FORM");

	Bureaucrat dave("Dave", 72);
	Bureaucrat eve("Eve", 45);
	Bureaucrat frank("Frank", 100);
	RobotomyRequestForm robotomyForm("Bender");

	std::cout << robotomyForm << "\n";
	std::cout << dave << "\n";
	std::cout << eve << "\n";
	std::cout << frank << "\n";
	frank.signForm(robotomyForm);
	dave.signForm(robotomyForm);
	frank.executeForm(robotomyForm);
	for (int i = 0; i < 4; ++i)
		eve.executeForm(robotomyForm);

	std::cout <<"\n";
	printSep("PRESIDENTIAL PARDON FORM");

	Bureaucrat grace("Grace", 25);
	Bureaucrat zaphod("Zaphod", 5);
	Bureaucrat harold("Harold", 50);
	PresidentialPardonForm pardonForm("Ford Prefect");

	std::cout << pardonForm << "\n";
	std::cout << grace << "\n";
	std::cout << zaphod << "\n";
	std::cout << harold << "\n";
	harold.signForm(pardonForm);
	grace.signForm(pardonForm);
	harold.executeForm(pardonForm);
	zaphod.executeForm(pardonForm);

	std::cout <<"\n";
	printSep("DOUBLE SIGNING");

	Bureaucrat ivan("Ivan", 1);
	ShrubberyCreationForm doubleSignForm("park");

	ivan.signForm(doubleSignForm);
	ivan.signForm(doubleSignForm);

	std::cout <<"\n";
	printSep("EXECUTE UNSIGNED FORM");

	Bureaucrat julia("Julia", 1);
	PresidentialPardonForm unsignedPardonForm("Arthur Dent");

	julia.executeForm(unsignedPardonForm);

	return 0;
}