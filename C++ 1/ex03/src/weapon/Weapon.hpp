/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 16:18:01 by ricsanto          #+#    #+#             */
/*   Updated: 2025/12/29 16:35:10 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#	define WEAPON_HPP

#include <string>
class Weapon
{
	public:
		Weapon();
		Weapon(std::string name);
		Weapon(const Weapon &other);
		Weapon &operator=(const Weapon &other);
		~Weapon();

		const std::string& getType(void);
		void setType(std::string type);
	private:
		std::string _type;

};
#endif