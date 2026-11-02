/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Generator.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 15:13:53 by ricsanto          #+#    #+#             */
/*   Updated: 2026/06/18 15:49:54 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Generator.hpp"

// =================== (Cons/Des)tructors ===================

Generator::Generator() {}
Generator::Generator(const Generator& other) { (void)other; }
Generator::~Generator() {}
Generator& Generator::operator=(const Generator& other) 
{ 
	(void)other;
	return *this;
}

// =================== Public ===================

Base *Generator::generate(void)
{
	switch (rand() % 3)
	{
		case 1:
			std::cout << BLUE << "Created new A class\n" << WHITE;
			return new A();
		case 2:
			std::cout << GREEN << "Created new B class\n" << WHITE;
			return new B();
		default:
			std::cout << YELLOW << "Created new C class\n" << WHITE;
			return new C();
	}
}
void Generator::identify(Base* p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "	Class of type A\n";
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "	Class of type B\n";
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "	Class of type C\n";
	else
		std::cout << "	Can't get class ID\n";
}

template<class T>
void idRef(Base& p, char c)
{
	try
	{
		T& cast = dynamic_cast<T&>(p);
		(void)cast;
		std::cout << "	Class of type " << c << "\n";
	}
	catch (std::exception &e)  {}
}

void Generator::identify(Base& p)
{
	idRef<A>(p, 'A');
	idRef<B>(p, 'B');
	idRef<C>(p, 'C');
}