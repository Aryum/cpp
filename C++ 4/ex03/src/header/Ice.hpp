/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:56:27 by ricsanto          #+#    #+#             */
/*   Updated: 2026/03/02 13:30:21 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#	define ICE_HPP

#include "AMateria.hpp"

class Ice : 
	public AMateria
{
	public:
		Ice();
		Ice(const Ice& other);
		~Ice();

		Ice& operator=(const Ice& other);
		AMateria* Clone(void) const;
		void Use(ICharacter& target);
};
#endif