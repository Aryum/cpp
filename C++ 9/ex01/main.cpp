/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 15:32:51 by ricsanto          #+#    #+#             */
/*   Updated: 2026/07/02 02:43:45 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char ** agrv)
{
	if (argc != 2)
	{
		std::cerr << RED << "Invalid number of arguments\n" << WHITE;
		return 1;
	}
	try
	{
		RPN::calculate(agrv[1]);
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << e.what() << WHITE << "\n";
		return 2;
	}
	return 0;
}