/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:06:20 by ricsanto          #+#    #+#             */
/*   Updated: 2026/01/09 12:08:34 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// =================== (Cons/Des)tructors ===================
Fixed::Fixed() :
	_value(0)
{
	std::cout << "Default constructor called\n";
}
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called\n";
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called\n";
	_value = other.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
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
