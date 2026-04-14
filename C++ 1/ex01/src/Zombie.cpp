/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:15:16 by ricsanto          #+#    #+#             */
/*   Updated: 2026/01/09 12:26:30 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// =================== (Cons/Des)tructors ===================

Zombie::Zombie() : _name("Mindless zombie")
{
	std::cout << BLUE << _name << ": was created" << WHITE << std::endl;
}

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << BLUE << _name << ": raised from the ground" << WHITE << std::endl;
}

Zombie::Zombie(const Zombie &other) : _name(other._name)
{
	std::cout << BLUE << _name << ": spawned another" << WHITE << std::endl;
}

Zombie::~Zombie()
{
	std::cout << RED << _name << ": was killed to death" << WHITE << std::endl;
}

// =================== Operator overload ===================

Zombie &Zombie::operator=(const Zombie &other)
{
	if (this != &other)
	{
		std::cout << MAGENTA << _name << ": was replaced by " << other._name << WHITE << std::endl;
		_name = other._name;
	}
	return *this;
}

// =================== Public ===================

void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ.." << std::endl;
}

void Zombie::rename(std::string new_name)
{
	std::cout << MAGENTA << _name << ": was renamed " << new_name << WHITE << std::endl;
	_name = new_name;
}