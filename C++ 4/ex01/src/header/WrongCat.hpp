/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:03:11 by ricsanto          #+#    #+#             */
/*   Updated: 2026/01/15 13:03:47 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:02:57 by ricsanto          #+#    #+#             */
/*   Updated: 2026/01/16 13:52:23 by ricsanto         ###   ########.fr       */
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