/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:07:26 by ricsanto          #+#    #+#             */
/*   Updated: 2026/03/02 13:30:35 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#	define MATERIASOURCE_HPP

#include <iostream>
#include <string>

#include "Color.hpp"
#include "IMateriaSource.hpp"


#define MAXMATERIA 4

class MateriaSource : 
	public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(std::string name);
		MateriaSource(const MateriaSource& other);
		~MateriaSource();

		MateriaSource& operator=(const MateriaSource& other);

		void LearnMateria(AMateria* m);
		AMateria* CreateMateria(std::string const &type);
	
	private:
		std::string _name;
		AMateria* _stored[MAXMATERIA];
};
#endif