/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:02:57 by ricsanto          #+#    #+#             */
/*   Updated: 2026/03/02 12:15:21 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#	define CAT_HPP

#include <string>
#include <iostream>
#include "Color.hpp"
#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat& other);
		~Cat();

		Cat& operator=(const Cat& other);
		virtual void MakeSound(void) const;

};
#endif