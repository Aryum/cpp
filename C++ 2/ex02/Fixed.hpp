/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:06:53 by ricsanto          #+#    #+#             */
/*   Updated: 2026/01/12 12:43:47 by ricsanto         ###   ########.fr       */
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
		
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;
		Fixed operator++(void);
		Fixed operator++(int);
		Fixed operator--(void);
		Fixed operator--(int);
		
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;
		
		static const Fixed& min(const Fixed &f1, const Fixed &f2);
		static Fixed& min(Fixed &f1, Fixed &f2);
		static const Fixed& max(const Fixed &f1, const Fixed &f2);
		static Fixed& max(Fixed &f1, Fixed &f2);

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