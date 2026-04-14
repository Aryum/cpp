/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:46:40 by ricsanto          #+#    #+#             */
/*   Updated: 2026/02/26 11:01:44 by ricsanto         ###   ########.fr       */
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

#define COUNT 4


class Harl
{
	enum Type
	{
		DEBUG,
		INFO,
		WARNING,
		ERROR,
		NONE
	};

	struct Function
	{
		Type type;
		void (Harl::*call)(void);
	};

	public:
		Harl();
		Harl(const Harl &other);
		Harl &operator=(const Harl &other);
		~Harl();
		void complain(std::string level);

	private:
		std::string _options[COUNT];
		Function _functions[COUNT];
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		void Ini(void);
		Type GetType(std::string level);

};

#endif