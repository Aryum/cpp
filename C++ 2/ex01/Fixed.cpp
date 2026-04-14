/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:06:20 by ricsanto          #+#    #+#             */
/*   Updated: 2026/01/09 12:16:02 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// =================== (Cons/Des)tructors ===================
Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	_value = 0;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called\n";
	_value = value << _fract_bits;
}
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called\n";
	_value = roundf(value * (1 << _fract_bits));
}
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called\n";
	*this = other;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}


// =================== Operators ===================

std::ostream &operator<<(std::ostream &out, const Fixed &c)
{
	out << c.toFloat();
	return out;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
		_value = other.getRawBits();
	return *this;
}

// =================== Public ===================

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return _value;
}
void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float Fixed::toFloat( void ) const
{
	return static_cast<float>(_value) / static_cast<float>(1 << _fract_bits);
}

int Fixed::toInt( void ) const
{
	return _value >> _fract_bits;
}
