/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:12:01 by ricsanto          #+#    #+#             */
/*   Updated: 2026/02/24 14:22:06 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/Zombie.hpp"

void Raised_dead(void)
{
	Zombie john = Zombie("John");
}

void Raised_by_machine(Zombie synthetic)
{
	synthetic.announce();
}
int main(int argc, char **argv)
{
	std::cout << GREEN << "Random Chump" << WHITE << std::endl;
	for (int i = 1; i < argc; i++)
	{
		randomChump(argv[i]);
	}
	std::cout << std::endl;


	std::cout << GREEN << "No param" << WHITE << std::endl;
	Zombie empty = Zombie();
	std::cout << std::endl;

	std::cout << GREEN << "Named" << WHITE << std::endl;
	Zombie bob = Zombie("Bob");
	Zombie tob = Zombie("Tob");
	bob.announce();
	std::cout << std::endl;

	std::cout << GREEN << "Summoned by function" << WHITE << std::endl;
	Raised_by_machine(tob);
	std::cout << std::endl;
	
	std::cout << GREEN << "Copied" << WHITE << std::endl;
	Zombie rob = bob;
	tob = rob;
	std::cout << std::endl;

	std::cout << GREEN << "Raised dead" << WHITE << std::endl;
	Raised_dead();
	std::cout << std::endl;

	

	std::cout << GREEN << "Summoned by allocation" << WHITE << std::endl;
	Zombie *jack = new Zombie("Jack");
	std::cout << std::endl;
	
	std::cout << GREEN << "Summoned by allocated zombie" << WHITE << std::endl;
	Zombie frog = *jack;
	std::cout << std::endl;

	std::cout << "Is jack still alive?" << std::endl;
	if (true)
	{
		delete jack;
		std::cout << YELLOW << "	Now it certaintly isn't" << WHITE << std::endl;
	}
	else
		std::cout << YELLOW << "	It is and his guts are leaking" << WHITE << std::endl;
		
	std::cout << GREEN << "Now they are all dead" << WHITE << std::endl;

}