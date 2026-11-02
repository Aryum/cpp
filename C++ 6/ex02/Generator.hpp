/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Generator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 15:11:06 by ricsanto          #+#    #+#             */
/*   Updated: 2026/06/18 15:41:29 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERATOR_HPP
# define GENERATOR_HPP

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <exception>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

class Generator
{
	public:
		static Base * generate(void);
		static void identify(Base* p);
		static void identify(Base& p);

	private:
		Generator(void);
		Generator(const Generator& other);
		~Generator(void);
		Generator& operator=(const Generator& other);
};
#endif