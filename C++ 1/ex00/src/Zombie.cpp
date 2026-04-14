/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:11:53 by ricsanto          #+#    #+#             */
/*   Updated: 2026/02/24 14:28:49 by ricsanto         ###   ########.fr       */
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
#pragma endregion
// =================== Public ===================

void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ.." << std::endl;
}