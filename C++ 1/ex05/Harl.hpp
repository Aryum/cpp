/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:46:40 by ricsanto          #+#    #+#             */
/*   Updated: 2026/01/06 16:58:26 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#	define HARL_HPP

#include <iostream>
#include <string>

#define WHITE "\033[0m"
#define GREEN "\033[1;32m"
#define MAGENTA "\033[1;35m"
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"

class Harl
{
	public:
		Harl();
		Harl(const Harl &other);
		Harl &operator=(const Harl &other);
		~Harl();
		void complain(std::string level);

	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
};

#endif