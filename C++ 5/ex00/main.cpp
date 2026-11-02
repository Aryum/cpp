/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 18:04:43 by ricsanto          #+#    #+#             */
/*   Updated: 2026/08/25 11:59:21 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

static void printSeparator(const std::string &label)
{
	std::cout << "\n=== " << label << " ===\n";
}

int main(void)
{
	printSeparator("Valid Construction");
	try
	{
		Bureaucrat alice("Alice", 1);
		Bureaucrat bob("Bob", 75);
		Bureaucrat charlie("Charlie", 150);
		std::cout << alice << "\n";
		std::cout << bob << "\n";
		std::cout << charlie << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << MAGENTA << "	Shouldn't have thrown exception\n" << WHITE;
		std::cout << "Unexpected exception: " << e.what() << WHITE << "\n";
	}

	printSeparator("Grade Too High Exception");
	try
	{
		Bureaucrat invalid("Invalid", 0);
	}
	catch (std::exception &e)
	{
		std::cout << GREEN  << "	Should have thrown exception\n" << WHITE; 
		std::cout << "Exception: " << e.what() << "\n";
	}

	printSeparator("Grade Too Low Exception");
	try
	{
		Bureaucrat invalid("Invalid", 151);
	}
	catch (std::exception &e)
	{
		std::cout << GREEN  << "	Should have thrown exception\n" << WHITE; 		std::cout << "Exception: " << e.what() << "\n";
	}

	printSeparator("Increment at highest grade");
	try
	{
		Bureaucrat tooHigh("tooHigh", 1);
		std::cout << tooHigh << "\n";
		tooHigh.gradeIncrement(); 
	}
	catch (std::exception &e)
	{
		std::cout << GREEN  << "	Should have thrown exception\n" << WHITE; 
		std::cout << "Exception: " << e.what() << "\n";
	}

	printSeparator("Decrement at lowest grade");
	try
	{
		Bureaucrat tooLow("tooLow", 150);
		std::cout << tooLow << "\n";
		tooLow.gradeDecrement();
	}
	catch (std::exception &e)
	{
		std::cout << GREEN  << "	Should have thrown exception\n" << WHITE; 
		std::cout << "Exception: " << e.what() << "\n";
	}

	printSeparator("Normal Increment and Decrement");
	try
	{
		Bureaucrat mid("Mid", 50);
		std::cout << mid << "\n";
		mid.gradeIncrement();
		std::cout << "After increment: " << mid << "\n";
		mid.gradeDecrement();
		std::cout << "After decrement: " << mid << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << MAGENTA << "	Shouldn't have thrown exception\n" << WHITE;
		std::cout << "Unexpected exception: " << e.what() << WHITE << "\n";
	}
	return 0;
}
