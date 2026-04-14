/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:12:09 by ricsanto          #+#    #+#             */
/*   Updated: 2026/01/14 15:42:45 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#	define SCAVTRAP_HPP

#include <string>
#include <iostream>

#include "ClapTrap.hpp"

#define WHITE "\033[0m"
#define GREEN "\033[1;32m"
#define MAGENTA "\033[1;35m"
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& clapTrap);
		~ScavTrap();

		ScavTrap& operator=(const ScavTrap& other);

		void guardGate(void);
	
	private:
		bool _isGuarding;
};

#endif