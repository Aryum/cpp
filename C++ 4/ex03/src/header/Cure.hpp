/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:56:24 by ricsanto          #+#    #+#             */
/*   Updated: 2026/03/02 13:30:11 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#	define CURE_HPP

#include "Color.hpp"
#include "AMateria.hpp"

class Cure : 
	public AMateria
{
	public:
		Cure();
		Cure(const Cure& other);
		~Cure();

		Cure& operator=(const Cure& other);
		AMateria* Clone(void) const;
		void Use(ICharacter& target);
};
#endif