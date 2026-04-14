/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:46:43 by ricsanto          #+#    #+#             */
/*   Updated: 2026/02/26 11:09:30 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << RED << "Harl needs instructions\n" << WHITE;
		return 0;
	}

	Harl harl;
	for (int i = 1; i < argc; i++)
		harl.complain(argv[i]);
	std::cout << "\n";
	
	Harl copy(harl);
	for (int i = 1; i < argc; i++)
		harl.complain(argv[i]);
	std::cout << "\n";

	Harl assign;
	assign = copy;
	for (int i = 1; i < argc; i++)
		harl.complain(argv[i]);
	std::cout << "\n";
}