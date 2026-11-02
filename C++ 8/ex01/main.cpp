/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 12:17:40 by ricsanto          #+#    #+#             */
/*   Updated: 2026/09/22 16:14:13 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <deque>
#include <iostream>
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

void printHeader(const char *msg)
{
	std::cout << BLUE << "-----------" << msg << "-----------\n" << WHITE;
}
void subjectTest()
{
	printHeader("Subject example");
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << "\n";
	std::cout << sp.longestSpan() << "\n";
}

void overflowTest()
{
	printHeader("Capacity overflow");
	Span sp = Span(2);

	sp.addNumber(1);
	sp.addNumber(2);
	try
	{
		sp.addNumber(3);
		std::cout << RED << "ERROR: no exception thrown" << WHITE <<"\n";
	}
	catch (std::exception &e)
	{
		std::cout << GREEN << "Caught: " << e.what() << WHITE << "\n";
	}
}

void notEnoughElementsTest()
{
	printHeader("Not enough elements");
	Span sp = Span(5);

	try
	{
		sp.shortestSpan();
		std::cout << RED << "ERROR: no exception thrown" << WHITE << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << GREEN << "shortestSpan empty - Caught: " << e.what() << WHITE << "\n";
	}
	sp.addNumber(42);
	try
	{
		sp.longestSpan();
		std::cout << RED << "ERROR: no exception thrown" << WHITE << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << GREEN << "longestSpan single - Caught: " << e.what() << WHITE << "\n";
	}
}

void addRangeTest()
{
	printHeader("Add range test");
	Span sp = Span(10000);

	std::deque<int> a;
	std::vector<int> b;

	for (int i = 0; i < 10000; i++)
	{
		if (i % 2 == 0)
			a.push_back(i);
		else
			b.push_back(i);
	}

	sp.addRange(a.begin(), a.end());
	sp.addRange(b.begin(), b.end());
	std::cout << "shortestSpan: " << sp.shortestSpan() << "\n";
	std::cout << "longestSpan:  " << sp.longestSpan() << "\n";
}


void addRangeOverflow()
{
	printHeader("Add range overflow test");
	Span sp = Span(3);

	std::vector<int> src;
	src.push_back(1);
	src.push_back(2);
	src.push_back(3);
	src.push_back(4);
	try
	{
		sp.addRange(src.begin(), src.end());
		std::cout << RED << "ERROR: no exception thrown" << WHITE << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << GREEN << "Caught: " << e.what() << WHITE << "\n";
	}
}

int	main(void)
{
	subjectTest();
	overflowTest();
	notEnoughElementsTest();
	addRangeTest();
	addRangeOverflow();
	return 0;
}