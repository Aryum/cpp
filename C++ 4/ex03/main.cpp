/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:16:48 by ricsanto          #+#    #+#             */
/*   Updated: 2026/03/02 13:31:33 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

void div()
{
	static int i;
	std::cout << "===== " << i << " =====\n";
	i++;
}

int main()
{
	
	div(); 
	std::cout << "Character initialization\n";
	Character tom = Character("Tom");
	ICharacter* player[] = { new Character("John"), new Character(), new Character(tom), new Gandalf()} ;
	
	div();
	std::cout << "Materia source initialization\n";
	IMateriaSource *src = new MateriaSource("Source");
	MateriaSource *base =  new MateriaSource("Base");
	base->LearnMateria(new Cure());
	IMateriaSource *cpy = new MateriaSource(*base);
	MateriaSource *assign =  new MateriaSource();
	*assign = *base;
	delete base;
	delete cpy;
	delete assign;

	src->LearnMateria(new Ice());
	src->LearnMateria(new Cure());
	//src->LearnMateria(new AMateria("I am an error"));
	
	div();
	std::cout << "Character inventory test\n";
	for (int i = 0; i <= INV_SPACE; i++)
		player[0]->Equip(src->CreateMateria("ice"));
	player[1]->Equip(src->CreateMateria("cure"));
	player[1]->Equip(src->CreateMateria("ice"));
	player[1]->Equip(src->CreateMateria("I dont exist"));
	
	div();
	std::cout << "Use test\n";
	player[0]->Use(1, *player[0]);
	player[1]->Use(0, *player[2]);
	player[0]->Use(5, *player[0]);
	player[0]->Use(0, *player[0]);
	
	div();
	std::cout << "Unequip test\n";
	for (int i = 0; i < 3; i++)
	{
		player[i]->Unequip(1);
		player[i]->Unequip(0);
	}
	div();
	std::cout << "test for full inventory\n";
	if (0)
	{
		for (int i = 0; i < 200; i++)
			player[0]->Equip(src->CreateMateria("cure"));
	}
	div();//	9
	for (int i = 0; i < 4; i++)
		delete player[i];
	div();//	10



	delete src;
	return 0;
}