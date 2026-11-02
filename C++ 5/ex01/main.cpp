/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 15:09:56 by ricsanto          #+#    #+#             */
/*   Updated: 2026/08/25 11:56:44 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

static void printSeparator(const std::string &label)
{
	std::cout << "\n=== " << label << " ===\n";
}

int	main(void)
{
	printSeparator("Empty form creation");
	try
	{
		Form f;
		std::cout << f << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << MAGENTA << "	Shouldn't have thrown exception\n" << WHITE;
		std::cout << "Exception: " << e.what() << "\n";
	}
	
	printSeparator("Valid Form creation");
	try
	{
		Form f("TaxReturn", 50, 30);
		std::cout << f << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << MAGENTA << "	Shouldn't have thrown exception\n" << WHITE;
		std::cout << "Exception: " << e.what() << "\n";
	}
	
	printSeparator("Form with grade too high");
	try
	{
		Form f("IllegalForm", 0, 30);
		std::cout << f << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << GREEN  << "	Should have thrown exception\n" << WHITE; 
		std::cout << "Exception: " << e.what() << "\n";
	}
	printSeparator("Form with grade too low");

	try
	{
		Form f("IllegalForm", 50, 151);
		std::cout << f << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << GREEN  << "	Should have thrown exception\n" << WHITE; 
		std::cout << "Exception: " << e.what() << "\n";
	}
	printSeparator("Bureaucrat with sufficient grade signs form");
	try
	{
		Bureaucrat	b("Alice", 40);
		Form		f("TaxReturn", 30, 50);
		std::cout << b << "\n";
		std::cout << f << "\n";
		b.signForm(f);
		std::cout << f << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << MAGENTA << "	Shouldn't have thrown exception in main\n" << WHITE;
		std::cout << "Exception: " << e.what() << "\n";
	}

	printSeparator("Bureaucrat with insufficient grade fails to sign");
	try
	{
		Bureaucrat b("Bob", 100);
		Form f("TopSecret", 10, 30);
		std::cout << b << "\n";
		std::cout << f << "\n";
		b.signForm(f);
	}
	catch (std::exception &e)
	{
		std::cout << MAGENTA << "	Shouldn't have thrown exception in main\n" << WHITE;
		std::cout << "Exception: " << e.what() << "\n";
	}

	printSeparator("Signing an already signed form");
	try
	{
		Bureaucrat	b("Carol", 1);
		Form		f("SimpleForm", 150, 150);
		b.signForm(f);
		b.signForm(f);
	}
	catch (std::exception &e)
	{
		std::cout << GREEN  << "	Should have thrown exception\n" << WHITE; 
		std::cout << "Exception: " << e.what() << "\n";
	}

	return (0);
}