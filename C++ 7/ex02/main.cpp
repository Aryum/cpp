/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 10:42:35 by ricsanto          #+#    #+#             */
/*   Updated: 2026/09/15 15:29:02 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

void	testDefaultConstruction(void)
{
	std::cout << BLUE << "\n--- default construction ---\n" << WHITE;
	Array<int>	arr;
	std::cout << "size = " << arr.size() << "\n";
	try
	{
		arr[0] = 1;
		std::cout << RED << "ERROR: no exception thrown" << WHITE << "\n";
	}
	catch (const std::exception &e)
	{
		std::cout << GREEN << "caught expected exception: " << e.what() << WHITE <<"\n";
	}
}

void	testNConstruction(void)
{
	std::cout << BLUE << "\n--- n-element construction (int) ---\n" << WHITE;
	Array<int>	arr(5);
	std::cout << "size = " << arr.size() << "\n";
	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << "arr[" << i << "] = " << arr[i] << "\n";
}

void	testFill(void)
{
	std::cout << BLUE << "\n--- fill and read back ---\n" << WHITE;
	Array<int>	arr(5);
	for (unsigned int i = 0; i < arr.size(); i++)
		arr[i] = i * 10;
	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << "arr[" << i << "] = " << arr[i] << "\n";
}

void	testOutOfBounds(void)
{
	std::cout << BLUE << "\n--- out of bounds access ---\n" << WHITE;
	Array<int>	arr(3);
	try
	{
		std::cout << arr[3] << "\n";
		std::cout << RED << "ERROR: no exception thrown" << WHITE << "\n";
	}
	catch (const std::exception &e)
	{
		std::cout << GREEN << "caught expected exception on arr[3]: " << e.what() << WHITE << "\n";
	}
	try
	{
		std::cout << arr[100] << "\n";
		std::cout << RED << "ERROR: no exception thrown" << WHITE << "\n";
	}
	catch (const std::exception &e)
	{
		std::cout << GREEN << "caught expected exception on arr[100]: " << e.what() << WHITE << "\n";
	}
}

void	testCopyIndependence(void)
{
	std::cout << BLUE << "\n--- copy constructor independence ---\n" << WHITE;
	Array<int>	original(3);
	for (unsigned int i = 0; i < original.size(); i++)
		original[i] = i;

	Array<int>	copy(original);
	copy[0] = 999;

	std::cout << "original[0] = " << original[0] << " (should be 0)" << "\n";
	std::cout << "copy[0] = " << copy[0] << " (should be 999)" << "\n";
}

void	testAssignmentIndependence(void)
{
	std::cout << BLUE << "\n--- assignment operator independence ---\n" << WHITE;
	Array<int>	a(3);
	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = i;

	Array<int>	b(5);
	b = a;
	std::cout << "b.size() after assignment = " << b.size() << " (should be 3)" << "\n";

	a[0] = 777;
	std::cout << "a[0] = " << a[0] << " (should be 777)" << "\n";
	std::cout << "b[0] = " << b[0] << " (should be 0, unaffected)" << "\n";
}

void	testNonPrimitiveType(void)
{
	std::cout << BLUE << "\n--- non-primitive type (std::string) ---\n" << WHITE;
	Array<std::string>	arr(3);
	arr[0] = "foo";
	arr[1] = "bar";
	arr[2] = "baz";
	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << "arr[" << i << "] = " << arr[i] << "\n";
}

void	testZeroSize(void)
{
	std::cout << BLUE << "\n--- explicit zero-size construction ---\n" << WHITE;
	Array<int>	arr(0);
	std::cout << "size = " << arr.size() << "\n";
	try
	{
		arr[0];
		std::cout << RED << "ERROR: no exception thrown" << WHITE << "\n";
	}
	catch (const std::exception &e)
	{
		std::cout << GREEN << "caught expected exception: " << e.what() << WHITE <<"\n";
	}
}

int main(void)
{
	testDefaultConstruction();
	testNConstruction();
	testFill();
	testOutOfBounds();
	testCopyIndependence();
	testAssignmentIndependence();
	testNonPrimitiveType();
	testZeroSize();
	return (0);
}