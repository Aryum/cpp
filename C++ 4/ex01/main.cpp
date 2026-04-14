/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:03:51 by ricsanto          #+#    #+#             */
/*   Updated: 2026/03/02 12:48:47 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/header/Animal.hpp"
#include "src/header/WrongAnimal.hpp"
#include "src/header/Cat.hpp"
#include "src/header/WrongCat.hpp"
#include "src/header/Dog.hpp"

void div()
{
	static int i;
	std::cout << "===== " << i << " =====\n";
	i++;
}
int main()
{
	div();
	Cat *smart = new Cat();
	smart->Add_Idea("Math");
	smart->Add_Idea("History");
	smart->Add_Idea("Milk");
	smart->Add_Idea("Birds");
	smart->Add_Idea("Bees");
	Cat *imposter = new Cat(*smart);
	delete smart;
	imposter->Print_Ideas();
	delete imposter;

	div();
	Animal *zoo[20];

	for (int i = 0; i < 20; i++)
	{
		if (i % 2 == 0)
		{
			zoo[i] = new Cat();
			dynamic_cast<Cat *>(zoo[i])->Add_Idea("Milk");
		}
		else
		{
			Dog *tmp = new Dog();
			tmp->Add_Idea("Bone");
			zoo[i] = tmp;
		}
		std::cout << "\n";
	}
	div();
	
	for (int i = 0; i < 20; i++)
	{
		zoo[i]->MakeSound();
		if (i % 2 == 0)
			dynamic_cast<Cat *>(zoo[i])->Print_Ideas();
		else
			dynamic_cast<Dog *>(zoo[i])->Print_Ideas();
	}
	
	div();
	for (int i = 0; i < 20; i++)
	{
		delete zoo[i];
		std::cout << "\n";
	}
	return (0);
}
