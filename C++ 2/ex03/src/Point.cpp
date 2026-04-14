/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 11:20:54 by ricsanto          #+#    #+#             */
/*   Updated: 2026/01/13 12:00:48 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// =================== (Cons/Des)tructors ===================

Point::Point() :
	_x(0), _y(0)
{}

Point::Point(float x, float y) :
	_x(x), _y(y)
{}

Point::Point(const Point& point) :
	_x(point._x), _y(point._y)
{}

Point::~Point()
{}

// =================== Operators ===================

Point& Point::operator=(const Point& other)
{
	(void)other;
	return *this;
}

bool Point::operator==(const Point &other) const
{
	return GetX() == other.GetX() && GetY() == other.GetY();
}

// =================== Public ===================

const Fixed& Point::GetX() const
{
	return _x;
}

const Fixed& Point::GetY() const
{
	return _y;
}
