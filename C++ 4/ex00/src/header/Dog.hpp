/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:03:01 by ricsanto          #+#    #+#             */
/*   Updated: 2026/01/16 15:20:56 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#	define DOG_HPP

#include <string>
#include <iostream>
#include "Color.hpp"
#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog& other);
		~Dog();

		Dog& operator=(const Dog& other);
		void MakeSound(void) const;
};
#endif