/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gandalf.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:19:51 by ricsanto          #+#    #+#             */
/*   Updated: 2026/03/02 13:30:15 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GANDALF_HPP
#	define GANDALF_HPP

#include <iostream>

#include "Color.hpp"
#include "ICharacter.hpp"

class Ground;

class Gandalf : 
	public ICharacter
{
	public:
		Gandalf();
		Gandalf(const Gandalf& other);
		~Gandalf();

		Gandalf& operator=(const Gandalf& other);

		const std::string& GetName(void) const;
		void Equip(AMateria *m);
		void Unequip(int idx);
		void Use(int idx, ICharacter& target);

	private:
		std::string _name;
		AMateria* _inventory[INV_SPACE];
};
#endif