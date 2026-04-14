/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 16:18:04 by ricsanto          #+#    #+#             */
/*   Updated: 2026/01/09 12:30:46 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>
#include <iostream>
#include "../weapon/Weapon.hpp"

class HumanB
{
	public:
		HumanB();
		HumanB(std::string name);
		HumanB(const HumanB &other);
		HumanB &operator=(const HumanB &other);
		~HumanB();
		void attack();
		void setWeapon(Weapon &weapon);

	private:
		std::string _name;
		Weapon *_weapon;
};
#endif