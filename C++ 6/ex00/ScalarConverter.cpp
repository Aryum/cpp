/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 18:17:08 by ricsanto          #+#    #+#             */
/*   Updated: 2026/09/14 12:03:21 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

Type ScalarConverter::_curType = Char;
char ScalarConverter::_charVal = 0;
int ScalarConverter::_intVal = 0;
float ScalarConverter::_floatVal = 0;
double ScalarConverter::_doubleVal = 0;
bool ScalarConverter::_isLiteral = 0;
std::string ScalarConverter::_literalVal = "";

// =================== (Cons/Des)tructors ===================

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter::~ScalarConverter() {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) 
{ 
	(void)other;
	return *this;
}

// =================== Public ===================

void ScalarConverter::convert(std::string str)
{
	_curType = getType(str);
	switch (_curType)
	{
		case Char:
			_charVal = str[0];
			break;
		case Int:
			handleInt(str);
			break;
		case Float:
			_floatVal = strtof(str.c_str(), NULL);
			break;
		case Double:
			_doubleVal = strtod(str.c_str(), NULL);
			break;
		case Invalid:
			std::cerr << RED << "INVALID INPUT\n" << WHITE;
			return;
	}
	convertChar();
	convertInt();
	convertFloat();
	convertDouble();
}

// =================== Private ===================

void ScalarConverter::handleInt(std::string str)
{
	long tmp = strtol(str.c_str(), NULL, 10);

	if (tmp >= INT_MIN && tmp <= INT_MAX)
		_intVal = tmp;
	else
	{
		_curType = Double;
		_doubleVal = strtod(str.c_str(), NULL);
	}
}
bool ScalarConverter::isValid(std::string str, Type &t)
{
	std::string valid(".f-+");
	size_t len = str.length();
	bool dot = false;
	bool digit = false;

 	for (size_t i = 0; i < len; i++)
	{
		if (!std::isdigit(str[i]))
		{
			if (valid.find(str[i]) == std::string::npos)
				return false;
			if (i != 0 && (str[i] == '+' || str[i] == '-'))
				return false;
			if (str[i] == 'f')
			{
				if (!digit || i != len - 1)
					return false;
			}
			if (str[i] == '.')
			{
				if (!digit)
					return false;
				if (i == len - 1)
					return false;
				if (!dot)
					dot = true;
				else
					return false;
			}
		}
		else
			digit = true;
	}
	if (str[len - 1] == 'f')
		t = Float;
	else if (dot)
		t = Double;
	return true;
}

Type ScalarConverter::getType(std::string str)
{
	std::string double_literals[4] = {"-inf", "+inf", "inf", "nan"};
	std::string float_literals[4] = {"-inff", "+inff", "inff", "nanf"};
	int len = str.length();

	if (str.empty())
		return Invalid;
	if (len == 1)
		return (std::isdigit(str[0]) ? Int : Char);
	_isLiteral = true;
	for (int i = 0; i < 4; i++)
	{
		if (str == double_literals[i])
		{
			_literalVal = double_literals[i];
			return Double;
		}
		if (str == float_literals[i])
		{
			_literalVal = double_literals[i];
			return Float;
		}
	}
	_isLiteral = false;
	Type tmp = Char;
	if (!isValid(str, tmp))
		return (Invalid);
	if (tmp != Char)
		return (tmp);
	return (Int);
}

template<typename T1, typename T2>
bool castVar(T1 &ret, T2 val, double low, double high)
{
	if (static_cast<double>(val) < low || static_cast<double>(val) > high)
		return false;
	ret = static_cast<T1>(val);
	return true;
}
void ScalarConverter::convertChar(void)
{
	bool possible = true;
	if (!_isLiteral)
	{
		switch (_curType)
		{
			case Double:
				possible = castVar<char, double>(_charVal, _doubleVal, CHAR_MIN, CHAR_MAX);
				break;
			case Int:
				possible = castVar<char, int>(_charVal, _intVal, CHAR_MIN, CHAR_MAX);
				break;
			case Float:
				possible = castVar<char, float>(_charVal, _floatVal, CHAR_MIN, CHAR_MAX);
				break;
			default:
				break;
		}
	}
	std::cout << YELLOW << "char: " << WHITE;
	if (!possible || _isLiteral)
		std::cout << "Impossible";
	else
	{
		if (!std::isprint(_charVal))
			std::cout << "Non displayable";
		else
			std::cout << '\'' << _charVal << '\'';
	}
	std::cout << "\n";
}

void ScalarConverter::convertInt(void)
{
	bool possible = true;
	if (!_isLiteral)
	{
		switch (_curType)
		{
			case Double:
				possible = castVar<int, double>(_intVal, _doubleVal, INT_MIN, INT_MAX);
				break;
			case Char:
				_intVal = static_cast<int>(_charVal);
				break;
			case Float:
				possible = castVar<int, float>(_intVal, _floatVal, INT_MIN, INT_MAX);
				break;
			default:
				break;
		}
	}
	std::cout << BLUE << "int: " << WHITE;
	if (!possible || _isLiteral)
		std::cout << "Impossible";
	else
		std::cout << _intVal;
	std::cout << "\n";
}
void ScalarConverter::convertFloat(void)
{
	bool possible = true;
	if (!_isLiteral)
	{
		switch (_curType)
		{
			case Double:
				possible = castVar<float, double>(_floatVal, _doubleVal, -FLT_MAX, FLT_MAX) ;
				break;
			case Char:
				_floatVal = static_cast<float>(_charVal);
				break;
			case Int:
				_floatVal = static_cast<float>(_intVal);
				break;
			default:
				break;
		}
	}
	std::cout << GREEN << "float: " << WHITE;
	if (!possible)
		std::cout << "Impossible";
	else if (_isLiteral)
		std::cout << _literalVal << "f";
	else
		std::cout << std::fixed << std::setprecision(1) << _floatVal << "f";
	std::cout << "\n";
}

void ScalarConverter::convertDouble(void)
{
	if (!_isLiteral)
	{
		switch (_curType)
		{
			case Float:
				_doubleVal = static_cast<double>(_floatVal);
				break;
			case Char:
				_doubleVal = static_cast<double>(_charVal);
				break;
			case Int:
				_doubleVal = static_cast<double>(_intVal);
				break;
			default:
				break;
		}
	}
	std::cout << MAGENTA << "double: " << WHITE;
	if (_isLiteral)
		std::cout << _literalVal;
	else
		std::cout << std::fixed << std::setprecision(1) << _doubleVal;
	std::cout << "\n";
}
