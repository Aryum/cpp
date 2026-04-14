/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 11:20:27 by ricsanto          #+#    #+#             */
/*   Updated: 2026/01/13 11:59:28 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#	define POINT_HPP

#include "Fixed.hpp"

#define WHITE "\033[0m"
#define GREEN "\033[1;32m"
#define MAGENTA "\033[1;35m"
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"

class Point
{
	public:
		Point();
		Point(float x, float y);
		Point(const Point& point);
		~Point();
		
		Point& operator=(const Point& other);
		bool operator==(const Point &other) const;

		const Fixed& GetX() const;
		const Fixed& GetY() const;
	private: 
		const Fixed _x;
		const Fixed _y;

};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif