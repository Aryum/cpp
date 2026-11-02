/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 11:59:26 by ricsanto          #+#    #+#             */
/*   Updated: 2026/10/06 13:49:11 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **agrv)
{
	try
	{
		PmergeMe::Sort(argc, agrv, false);
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << WHITE << "\n";
	}
}