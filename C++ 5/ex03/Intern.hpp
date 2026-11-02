/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:16:28 by ricsanto          #+#    #+#             */
/*   Updated: 2026/08/27 15:44:45 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#	define INTERN_HPP

#include <iostream>
#include <string>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

#ifndef	COLOR
#	define COLOR
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#endif

template <class T>
AForm*	generateForm(const std::string name, const std::string target);

struct FormEntry {
	std::string name;
	AForm* (*func)(const std::string,const std::string);
};

class Intern
{
	public:
		Intern();
		Intern(const Intern &other);
		~Intern();
		Intern& operator=(const Intern &other);

		AForm *makeForm(const std::string name, const std::string target);
		class InvalidFormException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};
#endif