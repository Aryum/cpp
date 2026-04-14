/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 13:31:59 by ricsanto          #+#    #+#             */
/*   Updated: 2026/03/02 13:32:09 by ricsanto         ###   ########.fr       */
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

		virtual void MakeSound(void) const;
		std::string GetType(void) const;

	protected:
		std::string _type;
		std::string _color;

		void PrintType(void) const;
};
#endif