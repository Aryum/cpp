/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:15:11 by ricsanto          #+#    #+#             */
/*   Updated: 2026/02/25 14:51:24 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#	define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <cstdlib>

#define WHITE "\033[0m"
#define GREEN "\033[1;32m"
#define MAGENTA "\033[1;35m"
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"

class Zombie
{
	public:
		Zombie();
		Zombie(std::string name);
		Zombie(const Zombie &other);
		Zombie &operator=(const Zombie &other);
		~Zombie();
		
		void announce(void);
		void rename(std::string new_name);

	private:
		std::string _name;
};

Zombie* zombieHorde(int N, std::string name);

#endif