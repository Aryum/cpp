/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ground.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:41:26 by ricsanto          #+#    #+#             */
/*   Updated: 2026/03/02 13:30:18 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GROUND_HPP
#	define GROUND_HPP

#define GROUND_SPACE 100

#include <iostream>
#include <string>

#include "Color.hpp"

class AMateria;

class Ground
{
	public:
		Ground(void);
		Ground(const Ground& other);
		~Ground();

		Ground& operator=(const Ground& other);

		void Add(AMateria* m);
		AMateria* Get(std::string item);

	private:
		AMateria* _dropped[GROUND_SPACE];
};

#endif