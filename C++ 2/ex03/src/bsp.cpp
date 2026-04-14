/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 11:41:20 by ricsanto          #+#    #+#             */
/*   Updated: 2026/01/13 12:20:41 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//bsp is the division of a space recursively
//divide the triangle into squares
//define bounds (max and lowest x and y)
//1st big square
//	check if x is bigger left end and


bool IsInside(Point triangle[3], int out_idx, Point const point)
{
	int line_idx[2];
	int a = 0;
	for (int i = 0; i < 3; i++)
	{
		if (i != out_idx)
		{
			line_idx[a] = i;
			a++;
		}
	}
	Point line[2] = { Point(triangle[line_idx[0]]), Point(triangle[line_idx[1]])};

	
	if (line[0].GetX() != line[1].GetX())
	{
		Fixed slope((line[0].GetY() - line[1].GetY())/(line[0].GetX() - line[1].GetX()));
		Fixed y_zero(line[0].GetY() - (slope * line[0].GetX()));
		
		if (triangle[out_idx].GetY() > (slope * triangle[out_idx].GetX() + y_zero).toFloat())
			return point.GetY() > slope * point.GetX() + y_zero;
		else if (triangle[out_idx].GetY() < (slope * triangle[out_idx].GetX() + y_zero).toFloat())
			return point.GetY() < slope * point.GetX() + y_zero;
		else
			return false;
	}
	else
	{
		if (triangle[out_idx].GetX() > line[0].GetX())
			return point.GetX() > line[0].GetX();
		else if (triangle[out_idx].GetX() < line[0].GetX())
			return point.GetX() < line[0].GetX();
		else
			return false;
	}
	
}


bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Point points[3] = { a, b, c };
	
	for (int i = 0; i < 3; i++)
	{
		if (!IsInside(points, i, point))
			return false;
	}
	return true;
}