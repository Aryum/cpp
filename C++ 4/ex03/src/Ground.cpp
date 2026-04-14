/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ground.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:50:21 by ricsanto          #+#    #+#             */
/*   Updated: 2026/03/02 13:30:58 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/ICharacter.hpp"
#include "header/AMateria.hpp"
#include "header/Ground.hpp"

// =================== (Cons/Des)tructors ===================

Ground::Ground(void)
{
	std::cout << YELLOW << "Ground was created\n" << WHITE;
	for (int i = 0; i < GROUND_SPACE; i++)
		_dropped[i] = NULL;
}

Ground::Ground(const Ground& other)
{
	std::cout << MAGENTA << "Ground was copied (why would you do this)\n" << WHITE;
	for (int i = 0; i < GROUND_SPACE; i++)
		_dropped[i] = other._dropped[i]->Clone();
}
Ground::~Ground()
{
	std::cout << MAGENTA << "Ground is cleaned\n" << WHITE;
	for (int i = 0; i < GROUND_SPACE; i++)
		delete _dropped[i];
}

// =================== Operators ===================

Ground& Ground::operator=(const Ground& other)
{
	if (this != &other)
	{
		std::cout << MAGENTA << "Reassigning ground (why would you do this)\n" << WHITE;
		for (int i = 0; i < GROUND_SPACE; i++)
		{
			delete _dropped[i];
			if (other._dropped[i] != NULL)
				_dropped[i] = other._dropped[i]->Clone();
		}
	}
	return *this;
}

// =================== Public ===================

void Ground::Add(AMateria* m)
{
	int i = 0;
	while (i < GROUND_SPACE)
	{
		if (_dropped[i] == NULL)
		{
			_dropped[i] = m;
			break;
		}
		i++;
	}
	if (i == GROUND_SPACE)
	{
		std::cout << RED << "Ground is too clutered removing ";
		std::cout << WHITE << m->GetType() << "\n";
		delete m;
	}
}

AMateria* Ground::Get(std::string item)
{
	for (int i = 0; i < GROUND_SPACE; i++)
	{
		if (_dropped[i] != NULL && _dropped[i]->GetType() == item)
		{
			std::cout << item;
			std::cout << BLUE << " was found on the ground!\n" << WHITE;
			AMateria *ret = _dropped[i];
			_dropped[i] = NULL;
			return ret;
		}
	}
	return NULL;
}
