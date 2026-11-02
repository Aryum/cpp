/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 13:07:35 by ricsanto          #+#    #+#             */
/*   Updated: 2026/06/18 13:09:22 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int agrc, char **agrv)
{
	if (agrc != 2)
	{
		std::cout << RED << "INVALID INPUT\n" << WHITE;
		return 1;
	}
	ScalarConverter::convert(agrv[1]);
	return 0;
}