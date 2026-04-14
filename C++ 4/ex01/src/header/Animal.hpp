/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:02:52 by ricsanto          #+#    #+#             */
/*   Updated: 2026/01/16 16:12:56 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#	define ANIMAL_HPP

#include <string>
#include <iostream>
#include "Color.hpp"

class Animal
{
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal& other);
		virtual ~Animal();

		Animal& operator=(const Animal& other);

		virtual void MakeSound(void) const;
		std::string GetType(void) const;

	protected:
		std::string _type;
		std::string _color;

		void PrintType(void) const;
};
#endif