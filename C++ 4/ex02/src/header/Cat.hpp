/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:02:57 by ricsanto          #+#    #+#             */
/*   Updated: 2026/03/02 13:31:51 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#	define CAT_HPP

#include <string>
#include <iostream>
#include "Color.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat& other);
		~Cat();

		Cat& operator=(const Cat& other);
		virtual void MakeSound(void) const;
		void Add_Idea(std::string idea);
		void Print_Ideas(void) const;
		
	private:
		Brain* _brain;

};
#endif