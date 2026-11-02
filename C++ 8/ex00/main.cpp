/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:41:35 by ricsanto          #+#    #+#             */
/*   Updated: 2026/06/22 11:03:09 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

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

int main()
{
	std::vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	printHeader("Vector containing element");
	try
	{
		std::vector<int>::const_iterator it = easyfind(v, 3);
		std::cout << GREEN << "found in vector: " << *it << WHITE << "\n";
	}
	catch (const std::exception &e)
	{
		std::cout << RED << "vector: " << e.what() << WHITE << "\n";
	}
	
	std::cout << "\n";

	printHeader("Vector not having element");
	try
	{
		std::vector<int>::const_iterator it = easyfind(v, 99);
		std::cout << RED << "found in vector: " << *it << WHITE << "\n";
	}
	catch (const std::exception &e)
	{
		std::cout << GREEN << "vector: " << e.what() << WHITE << "\n";
	}

	std::cout << "\n";
	std::cout << "\n";

	std::list<int> l;

	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	printHeader("List containing element");
	try
	{
		std::list<int>::const_iterator it = easyfind(l, 20);
		std::cout << GREEN << "found in list: " << *it << WHITE << "\n";
	}
	catch (const std::exception &e)
	{
		std::cout << RED << "list: " << e.what() << WHITE << "\n";
	}
	std::cout << "\n";
	
	printHeader("List not having element");
	try
	{
		std::list<int>::const_iterator it = easyfind(l, 99);
		std::cout << RED << "found in list: " << *it << WHITE << "\n";
	}
	catch (const std::exception &e)
	{
		std::cout << GREEN << "list: " << e.what() << WHITE << "\n";
	}

	return 0;
}