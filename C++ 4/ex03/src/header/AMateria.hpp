/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:52:43 by ricsanto          #+#    #+#             */
/*   Updated: 2026/03/02 13:30:03 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#	define AMATERIA_HPP

#include <string>
#include <iostream>
#include "Color.hpp"

class ICharacter;

class AMateria
{
	public:
		AMateria(void);
		AMateria(const AMateria& other);
		AMateria(const std::string& type);
		virtual ~AMateria();

		AMateria& operator=(const AMateria& other);

		const std::string& GetType(void) const;
		virtual AMateria* Clone(void) const = 0;
		virtual void Use(ICharacter& target);

	protected:
			std::string _type;

};
#endif