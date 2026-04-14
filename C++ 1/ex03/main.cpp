/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 21:05:58 by ricsanto          #+#    #+#             */
/*   Updated: 2026/02/25 14:54:39 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/header.hpp"

int main()
{
	Weapon club_A = Weapon("crude spiked club");
	HumanA bob("Bob", club_A);
	bob.attack();
	club_A.setType("some other type of club");
	bob.attack();


	Weapon club_B = Weapon("mourning star");
	HumanB jim("Jim");
	jim.attack();
	jim.setWeapon(club_B);
	jim.attack();
	return 0;
}