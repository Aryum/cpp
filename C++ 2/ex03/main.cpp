/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:39:54 by ricsanto          #+#    #+#             */
/*   Updated: 2026/02/25 11:13:40 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/Point.hpp"
#include <string.h>

Point Get_Point(std::string prompt)
{
	std::string x;
	std::string y;

	std::cout << prompt << "\n";
	std::cout << "	x:";
	std::getline(std::cin, x);
	std::cout << "	y:";
	std::getline(std::cin, y);
	return Point(atoi(x.c_str()), atoi(y.c_str()));
}

int main( void ) 
{
	Point triangle[3] = {Get_Point("T_1"), Get_Point("T_2"), Get_Point("T_3")};
	std::cout << "\n";
	Point point(Get_Point("Test"));

	for (int y = 49; y >= 0; y--)
	{
		for (int x = 0; x < 50; x++)
		{
			Point cur(x,y);
			bool islimit = false;
			std::string color;
			for (int j = 0; j < 3; j++)
			{
				if (cur == triangle[j])
				{
					if (cur == point)
						color = MAGENTA;
					else
						color = GREEN;
					islimit = true;
					break;
				}
			}
			if (!islimit)
			{
				if (cur == point)
					color = RED;
				else if (bsp(triangle[0], triangle[1], triangle[2], cur))
					color = BLUE;
				else
					color = WHITE;
			}
			std::cout << color << "#" << WHITE;
		
		}

		std::cout << std::endl;
	}
	if(bsp(triangle[0], triangle[1], triangle[2], point))
		std::cout << GREEN << "It belongs \n" << WHITE;
	else
		std::cout << RED << "It doesnt belong\n" << WHITE;

	return 0;
}