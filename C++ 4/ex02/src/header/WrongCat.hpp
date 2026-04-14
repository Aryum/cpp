/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 13:32:13 by ricsanto          #+#    #+#             */
/*   Updated: 2026/03/02 13:32:23 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#	define WRONGCAT_HPP

#include <string>
#include <iostream>
#include "Color.hpp"
#include "Animal.hpp"

class WrongCat : public Animal
{
	public:
		WrongCat();
		WrongCat(const WrongCat& other);
		~WrongCat();

		WrongCat& operator=(const WrongCat& other);
		void MakeSound(void) const;

};
#endif