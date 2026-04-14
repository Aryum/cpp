/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:02:52 by ricsanto          #+#    #+#             */
/*   Updated: 2026/01/16 12:23:53 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#	define WRONGANIMAL_HPP

#include <string>
#include <iostream>
#include "Color.hpp"

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal& other);
		~WrongAnimal();

		WrongAnimal& operator=(const WrongAnimal& other);

		void MakeSound(void) const;
		std::string GetType(void) const;

	protected:
		std::string _type;
		std::string _color;

		void PrintType(void) const;
};
#endif