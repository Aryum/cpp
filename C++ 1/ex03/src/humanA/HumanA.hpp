/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 16:18:11 by ricsanto          #+#    #+#             */
/*   Updated: 2026/01/09 12:30:55 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#	define HUMANA_HPP

#include <string>
#include <iostream>
#include "../weapon/Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string name, Weapon& weapon);
		HumanA(const HumanA &other);
		~HumanA();

		HumanA &operator=(const HumanA &other);
		void attack();

	private:
		std::string _name;
		Weapon &_weapon;
};

#endif