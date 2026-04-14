/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:06:53 by ricsanto          #+#    #+#             */
/*   Updated: 2026/01/08 15:44:18 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#	define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &other);
		~Fixed();

		Fixed &operator=(const Fixed &other);

		void setRawBits(int const raw);
		int getRawBits(void) const;
		float toFloat( void ) const;
		int toInt( void ) const;
		
	private:
		int _value;
		const static int _fract_bits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &c);

#endif