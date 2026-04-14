/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:17:09 by ricsanto          #+#    #+#             */
/*   Updated: 2026/03/02 13:44:06 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/MateriaSource.hpp"
#include "header/AMateria.hpp"

// =================== (Cons/Des)tructors ===================

MateriaSource::MateriaSource() :
	_name("Undefined")
{
	std::cout << YELLOW << "Created a new source of materia\n" << WHITE;
	for (int i = 0; i < MAXMATERIA; i++)
		_stored[i] = NULL;
}

MateriaSource::MateriaSource(std::string name) :
	_name(name)
{
	std::cout << YELLOW << "Created ";
	std::cout << WHITE << _name;
	std::cout << YELLOW << " source of materia";
	std::cout << WHITE << "\n";
	for (int i = 0; i < MAXMATERIA; i++)
		_stored[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) :
	_name(other._name)
{
	std::cout << WHITE << _name;
	std::cout << YELLOW << " source of materia was replicated";
	std::cout << WHITE << "\n";
	for (int i = 0; i < MAXMATERIA; i++)
	{
		if (other._stored[i] != NULL)
			_stored[i] = other._stored[i]->Clone();
		else
			_stored[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MAXMATERIA; i++)
		delete _stored[i];
	std::cout << WHITE << _name;
	std::cout << YELLOW << " source of materia was destroyed";
	std::cout << WHITE << "\n";
}

// =================== Operators ===================

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (&other != this)
	{
		for (int i = 0; i < MAXMATERIA; i++)
		{
			delete _stored[i];
			if (other._stored[i] != NULL)
				_stored[i] = other._stored[i]->Clone();
		}
		std::cout << WHITE << other._name;
		std::cout << YELLOW << " source of materia was copied to ";
		std::cout << WHITE << _name << "\n";
		_name = other._name;
	}
	return *this;
}

// =================== Public ===================

void MateriaSource::LearnMateria(AMateria* m)
{
	if (m == NULL)
	{
		std::cout << RED << "Void materias not yet suported in ";
		std::cout << WHITE << _name;
		std::cout << WHITE << " source\n";
		return ;
	}
	int i = 0;
	while (i < MAXMATERIA)
	{
		if (_stored[i] == NULL)
		{
			_stored[i] = m;
			break;
		}
		i++;
	}
	if (i == MAXMATERIA)
	{
		std::cout << RED << "Cannot add more materia to ";
		std::cout << WHITE << _name;
		std::cout << RED << " source";
		std::cout << WHITE << "\n";
	}
}

AMateria* MateriaSource::CreateMateria(std::string const &type)
{
	int i = 0;
	while (i < MAXMATERIA)
	{
		if (_stored[i] == NULL)
			break;
		if (_stored[i]->GetType() == type)
			return _stored[i]->Clone();
		i++;
	}
	std::cout << WHITE << type;
	std::cout << RED << " was not found in ";
	std::cout << WHITE << _name;
	std::cout << RED << " materia source";
	std::cout << WHITE << "\n";
	return NULL;
}
