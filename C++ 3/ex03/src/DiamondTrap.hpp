/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:33:34 by ricsanto          #+#    #+#             */
/*   Updated: 2026/01/14 16:18:37 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP


#include <string>
#include <iostream>

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#define WHITE "\033[0m"
#define GREEN "\033[1;32m"
#define MAGENTA "\033[1;35m"
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap();
		DiamondTrap(std::string _name);
		DiamondTrap(const DiamondTrap& diamondTrap);
		~DiamondTrap();

		DiamondTrap& operator=(const DiamondTrap& other);
		
		void attack(const std::string& target);
		void whoAmI(void);

	private:
		std::string _name;
};
#endif