/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:46:43 by ricsanto          #+#    #+#             */
/*   Updated: 2026/01/09 12:34:43 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;
	switch (argc)
	{
		case 1:
			std::cout << RED <<"[ Harl has nothing to complain ]\n" << WHITE;
			return 1;
		case 2:
			harl.complain(argv[1]);
			return 0;
		default:
			std::cout << RED <<"[ Multiple levels inserted harl is confused ]\n" << WHITE;
			return 1;
	}
}