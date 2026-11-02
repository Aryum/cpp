/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 15:16:02 by ricsanto          #+#    #+#             */
/*   Updated: 2026/06/18 15:46:17 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "Generator.hpp"
#include <iostream>

int main(void)
{
	srand(time(NULL));

	Base* p = Generator::generate();

	std::cout << "identify by pointer: \n";
	Generator::identify(p);

	std::cout << "identify by reference: \n";
	Generator::identify(*p);

	delete p;

	return (0);
}