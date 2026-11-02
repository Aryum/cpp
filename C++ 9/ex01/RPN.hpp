/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 15:31:38 by ricsanto          #+#    #+#             */
/*   Updated: 2026/09/21 14:03:58 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#	define RPN_HPP

#include <stack>
#include <string>
#include <exception>
#include <cctype>
#include <iostream>
#include <limits>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

class RPN
{
	public:
		static void calculate(std::string expression);
	
		class InvalidSpaceException : public std::exception
		{
			virtual const char *what() const throw();
		};

		class ExpectedSpaceException : public std::exception
		{
			virtual const char *what() const throw();
		};

		class InvalidNumberException : public std::exception
		{
			virtual const char *what() const throw();
		};

		class NotEnoughNumbersException : public std::exception
		{
			virtual const char *what() const throw();
		};
		
		class InvalidTokenException : public std::exception
		{
			virtual const char *what() const throw();
		};

		class DivisionByZeroException : public std::exception
		{
			virtual const char *what() const throw();
		};

		class MissingOperationsException : public std::exception
		{
			virtual const char *what() const throw();
		};

		class OverflowException : public std::exception
		{
			virtual const char *what() const throw();
		};

	private:
		RPN();
		RPN(const RPN &other);
		~RPN();

		RPN &operator=(const RPN &other);
		static void pushNbr(int nbr);
		static void popNbr(char c);

		static std::stack<int> _stack;
};
#endif