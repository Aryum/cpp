/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:46:36 by ricsanto          #+#    #+#             */
/*   Updated: 2026/02/26 11:03:22 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// =================== (Cons/Des)tructors ===================

Harl::Harl() 
{
	std::cout << "Hello from harl\n";
}

Harl::Harl(const Harl &other)
{
	std::cout << "Harl has been copied\n";

}

Harl::~Harl()
{
	std::cout << "Someone murdered Harl\n";
}

// =================== Operators ===================

Harl &Harl::operator=(const Harl &other)
{
	std::cout << "Harl has been assigned\n";
	return *this;
}

// =================== Private ===================

void Harl::debug(void)
{
	std::cout << YELLOW <<
	"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" <<
	WHITE << "\n";

}

void Harl::info(void)
{
	std::cout << GREEN <<
	"I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn’t be asking for more!" <<
	WHITE << "\n";
}

void Harl::warning(void)
{
	std::cout << BLUE <<
	"I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." <<
	WHITE << "\n";
}

void Harl::error(void)
{
	std::cout << MAGENTA <<
	"This is unacceptable! I want to speak to the manager now." <<
	WHITE << "\n";

}

// =================== Public ===================

void Harl::complain(std::string level)
{
	std::string options[] {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*comment[])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (level == options[i])
		{
			(this->*comment[i])();
				return ;
		}
	}
	std::cout << RED << "Level not found" << WHITE << "\n";
	return ;
}
