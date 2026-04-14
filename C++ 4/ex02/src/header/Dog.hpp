/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:03:01 by ricsanto          #+#    #+#             */
/*   Updated: 2026/03/02 13:31:58 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#	define DOG_HPP

#include <string>
#include <iostream>
#include "Color.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog& other);
		~Dog();

		Dog& operator=(const Dog& other);
		void MakeSound(void) const;
		void Add_Idea(std::string idea);
		void Print_Ideas(void) const;
	
		private:
			Brain* _brain;
};
#endif