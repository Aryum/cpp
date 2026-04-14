/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:15:21 by ricsanto          #+#    #+#             */
/*   Updated: 2026/01/09 12:27:21 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/Zombie.hpp"

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cerr << RED << "Usage <count> <name>\n" << WHITE;
		return 1;
	}

	int count = atoi(argv[1]);
	if (count == 0)
	{
		std::cerr << RED << "Invalid number\n" << WHITE;
		return 1;
	}
	Zombie *arr = zombieHorde(count, argv[1]);
	delete[] arr;
	return 0;
}