/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:05:40 by ricsanto          #+#    #+#             */
/*   Updated: 2026/03/02 13:30:24 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#	define ICHARACTER_HPP

#include <string>

#define INV_SPACE 4

class AMateria;

class ICharacter
{
	public:
		virtual ~ICharacter() {};
		virtual const std::string& GetName(void) const = 0;
		virtual void Equip(AMateria* m) = 0;
		virtual void Unequip(int idx) = 0;
		virtual void Use(int idx, ICharacter& target) = 0;

};
#endif