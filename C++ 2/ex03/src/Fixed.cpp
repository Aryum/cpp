/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:06:20 by ricsanto          #+#    #+#             */
/*   Updated: 2026/01/12 15:50:22 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// =================== (Cons/Des)tructors ===================

Fixed::Fixed()
{
	_value = 0;
}

Fixed::Fixed(const int value)
{
	_value = value << _fract_bits;
}
Fixed::Fixed(const float value)
{
	_value = roundf(value * (1 << _fract_bits));
}
Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed::~Fixed()
{}

// =================== Operators ===================

std::ostream &operator<<(std::ostream &out, const Fixed &c)
{
	out << c.toFloat();
	return out;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		_value = other.getRawBits();
	return *this;
}

// =================== Math operation ===================

Fixed Fixed::operator+(const Fixed &other) const
{
	return (Fixed(toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return (Fixed((toFloat() - other.toFloat())));
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return (Fixed(toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return (Fixed(toFloat() / other.toFloat()));
}

Fixed Fixed::operator++(void)
{
	++_value;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed last(*this);

	_value++;
	return last;
}

Fixed Fixed::operator--(void)
{
	--_value;
	return *this;
}
Fixed Fixed::operator--(int)
{
	Fixed last(*this);

	_value--;
	return last;
}

// =================== Comparison ===================

bool Fixed::operator>(const Fixed &other) const
{
	return _value > other._value;
}

bool Fixed::operator<(const Fixed &other) const
{
	return _value < other._value;
}

bool Fixed::operator>=(const Fixed &other) const
{
	return _value >= other._value;

}
bool Fixed::operator<=(const Fixed &other) const
{
	return _value <= other._value;
}

bool Fixed::operator==(const Fixed &other) const
{
	return _value == other._value;
}

bool Fixed::operator!=(const Fixed &other) const
{
	return _value != other._value;
}

// =================== Static ===================

const Fixed& Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1.toFloat() < f2.toFloat())
		return f1;
	return f2;
}
 Fixed& Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1.toFloat() < f2.toFloat())
		return f1;
	return f2;
}
 const Fixed& Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1.toFloat() > f2.toFloat())
		return f1;
	return f2;
}
Fixed& Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1.toFloat() > f2.toFloat())
		return f1;
	return f2;
}

// =================== Public ===================

int Fixed::getRawBits(void) const
{
	return _value;
}
void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(_value) / static_cast<float>(1 << _fract_bits);
}

int Fixed::toInt(void) const
{
	return _value >> _fract_bits;
}
