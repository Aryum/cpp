/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:03:51 by ricsanto          #+#    #+#             */
/*   Updated: 2026/03/02 12:22:12 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/header/Animal.hpp"
#include "src/header/WrongAnimal.hpp"
#include "src/header/Cat.hpp"
#include "src/header/WrongCat.hpp"
#include "src/header/Dog.hpp"

void test(Animal& animal)
{
	std::cout << "	type " << animal.GetType() << "\n";
	animal.MakeSound();
}

void div()
{
	static int i;
	std::cout << "===== " << i << " =====\n";
	i++;
}
int main()
{
	div();
	Animal unknown = Animal();
	Animal bird = Animal("Bird");
	Animal bird_jr = Animal(bird);
	Animal bee = Animal("Bee");
	bird = bee;
	div();
	Dog dog;
	Dog dog_jr(dog);
	Dog dog_bro;
	dog_bro = dog;

	Animal simple_dog("Simple dog");
	simple_dog = dog;
	div();
	Cat cat;
	Cat cat_jr = Cat(cat);
	Cat cat_bro;
	cat_bro = cat;
	
	Animal weird_cat("Weird looking Cat");
	weird_cat = simple_dog;
	div();
	test(unknown);
	test(bird);
	test(bird_jr);
	test(dog);
	dog.MakeSound();
	test(cat);
	cat.MakeSound();
	div();
	WrongCat w_cat;
	WrongAnimal *w_animal;
	w_animal = &w_cat;
	w_cat.MakeSound();
	w_animal->MakeSound();
	div();
	return (0);
}
