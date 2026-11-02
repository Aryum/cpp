/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 10:09:27 by ricsanto          #+#    #+#             */
/*   Updated: 2026/06/19 10:09:55 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#include "iter.hpp"

void	printInt(int &n)
{
	std::cout << n << " ";
}

void	printConstInt(const int &n)
{
	std::cout << n << " ";
}

void	doubleInt(int &n)
{
	n *= 2;
}

template<typename T>
void	printElem(const T &elem)
{
	std::cout << elem << " ";
}

int main(void)
{
	int intArr[5] = {1, 2, 3, 4, 5};
	std::string strArr[3] = {"foo", "bar", "baz"};

	std::cout << "-- int array, non-const ref function --" << "\n";
	iter(intArr, 5, printInt);
	std::cout << "\n";

	std::cout << "-- int array, const ref function --" << "\n";
	iter(intArr, 5, printConstInt);
	std::cout << "\n";

	std::cout << "-- int array, modifying function --" << "\n";
	iter(intArr, 5, doubleInt);
	iter(intArr, 5, printInt);
	std::cout << "\n";

	std::cout << "-- string array, template function --" << "\n";
	iter(strArr, 3, printElem<std::string>);
	std::cout << "\n";

	std::cout << "-- const int array --" << "\n";
	const int constArr[4] = {10, 20, 30, 40};
	iter(constArr, 4, printConstInt);
	std::cout << "\n";

	return (0);
}