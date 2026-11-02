/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 18:04:41 by ricsanto          #+#    #+#             */
/*   Updated: 2026/06/18 12:37:46 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#	define SCALARCONVERTER_HPP

#include <exception>
#include <string>
#include <cstdlib>
#include <iostream>
#include <cctype>
#include <climits>
#include <cfloat>
#include <iomanip>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

enum Type
{
	Char,
	Int,
	Float,
	Double,
	Invalid
};

class ScalarConverter
{
	public:
		static void convert(std::string str);

	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& other);
		~ScalarConverter(void);
		ScalarConverter& operator=(const ScalarConverter& other);
		static Type _curType;
		static char _charVal;
		static int _intVal;
		static float _floatVal;
		static double _doubleVal;
		static bool _isLiteral;
		static std::string _literalVal;
		static void handleInt(std::string str);
		static bool isValid(std::string str, Type &t);
		static Type getType(std::string str);
		static void convertChar(void);
		static void convertInt(void);
		static void convertFloat(void);
		static void convertDouble(void);

};
#endif