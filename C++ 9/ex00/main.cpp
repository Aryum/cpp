/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 09:22:37 by ricsanto          #+#    #+#             */
/*   Updated: 2026/06/26 15:21:39 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <sstream>
#include <iostream>
#include <string>

void printError(std::string msg)
{
	std::cerr << RED << "Error: " << msg << WHITE << "\n";
}

int main(int argc, char** agrv)
{
	if (argc != 2)
	{
		if (argc > 2)
			printError("Too many arguments");
		else
			printError("Too few arguments");
		return 1;
	}
	try
	{
		BitcoinExchange be;
		be.readDatabase(agrv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << WHITE << '\n';
	}
}