/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:46:36 by ricsanto          #+#    #+#             */
/*   Updated: 2026/02/26 11:07:08 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// =================== (Cons/Des)tructors ===================

Harl::Harl() 
{
	std::cout << "Hello from harl\n";
	Ini();
}

Harl::Harl(const Harl &other)
{
	std::cout << "Harl has been copied\n";
	Ini();
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

void Harl::Ini()
{
	_functions[0] = 
	{
		DEBUG,
		&Harl::debug
	};
	_functions[1] = 
	{
		INFO,
		&Harl::info
	};
	_functions[2] = 
	{
		WARNING,
		&Harl::warning
	};
	_functions[3] = 
	{
		ERROR,
		&Harl::error
	};
	_options[0] = "DEBUG";
	_options[1] = "INFO";
	_options[2] = "WARNING";
	_options[3] = "ERROR";
}

void Harl::debug(void)
{
	std::cout << GREEN << "[ DEBUG ]\n" << WHITE;
	std::cout << YELLOW <<
	"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" <<
	WHITE << "\n\n";

}

void Harl::info(void)
{
	std::cout << WHITE << "[ INFO ]\n" << WHITE;
	std::cout << YELLOW <<
	"I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn’t be asking for more!" <<
	WHITE << "\n\n";
}

void Harl::warning(void)
{
	std::cout << BLUE << "[ WARNING ]\n" << WHITE;
	std::cout << YELLOW <<
	"I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." <<
	WHITE << "\n\n";
}

void Harl::error(void)
{
	std::cout << MAGENTA << "[ ERROR ]\n" << WHITE;
	std::cout << YELLOW <<
	"This is unacceptable! I want to speak to the manager now." <<
	WHITE << "\n\n";

}

Harl::Type Harl::GetType(std::string level)
{
	for (int i = 0; i < COUNT; i++)
	{
		if (level == _options[i])
			return static_cast<Harl::Type>(i);
	}
	return NONE;
}

// =================== Public ===================

void Harl::complain(std::string level)
{
	Type type = GetType(level);
	switch (type)
	{
		case DEBUG:
			debug();
		case INFO:
			info();
		case WARNING:
			warning();
		case ERROR:
			error();
			break;
		default:
			std::cout << RED << "[  Probably complaining about insignificant problems ]" << WHITE << "\n";
	}
	return ;
}
