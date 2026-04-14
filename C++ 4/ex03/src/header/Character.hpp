/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 13:29:23 by ricsanto          #+#    #+#             */
/*   Updated: 2026/03/02 13:38:12 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#	define CHARACTER_HPP

#include <iostream>

#include "Color.hpp"
#include "ICharacter.hpp"

class Ground;

class Character : 
	public ICharacter
{
	public:
		Character();
		Character(const Character& other);
		Character(const std::string& name);
		~Character();

		Character& operator=(const Character& other);

		const std::string& GetName(void) const;
		void Equip(AMateria *m);
		void Unequip(int idx);
		void Use(int idx, ICharacter& target);

	private:
		std::string _name;
		AMateria* _inventory[INV_SPACE];
		static unsigned int _count;
		static bool _createdGround;
		static Ground *_ground;
};
#endif