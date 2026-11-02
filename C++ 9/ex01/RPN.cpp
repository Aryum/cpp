/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:38:44 by ricsanto          #+#    #+#             */
/*   Updated: 2026/10/12 12:07:24 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::stack<int> RPN::_stack = std::stack<int>();

// =================== (Cons/Des)tructors ===================

RPN::RPN() {}
RPN::RPN(const RPN &other) { (void)other; }
RPN::~RPN() {}

// =================== Operators ===================
RPN& RPN::operator=(const RPN &other) 
{
	(void)other;
	return *this;
}

// =================== Public ===================

void RPN::calculate(std::string expression)
{
	std::string operation("+-/*");
	bool expectedSpace = false;
	for (size_t i = 0; i < expression.size(); i++)
	{
		if (expression[i] == ' ')
		{
			if (!expectedSpace)
				throw InvalidSpaceException();
			expectedSpace = false;
		}
		else if (expression[i] != ' ' && expectedSpace)
			throw ExpectedSpaceException();
		else if (std::isdigit(expression[i]))
		{
			if (std::isdigit(expression[i + 1]))
				throw InvalidNumberException();
			pushNbr(expression[i] - '0');
			expectedSpace = true;
		}
		else if (operation.find(expression[i]) != std::string::npos)
		{
			if (_stack.size() < 2)
				throw NotEnoughNumbersException();
			popNbr(expression[i]);
			expectedSpace = true;
		}
		else
		{
			std::cerr << "	->" << expression[i] << "\n";
			throw InvalidTokenException();
		}
	}
	if (_stack.size() != 1)
		throw MissingOperationsException();
	std::cout << _stack.top() << "\n";
}

// =================== Private ===================
void RPN::pushNbr(int nbr)
{
	_stack.push(nbr);
}

void RPN::popNbr(char c)
{
	int a;
	int b;

	b = _stack.top();
	_stack.pop();
	a = _stack.top();
	_stack.pop();
	switch (c)
	{
		case '+':
			if (a > std::numeric_limits<int>::max() - b)
				throw OverflowException();
			pushNbr(a + b);
			break;
		case '-':
			if (a < std::numeric_limits<int>::min() + b)
				throw OverflowException();
			pushNbr(a - b);
			break;
		case '/':
			if(b == 0)
				throw DivisionByZeroException();
			if (b == -1 && a == std::numeric_limits<int>::min())
				throw OverflowException();
			pushNbr(a / b);
			break;
		case '*':
			if (b != 0 && a > std::numeric_limits<int>::max() / b)
				throw OverflowException();
			if (b != 0 && a < std::numeric_limits<int>::min() / b)
				throw OverflowException();
			pushNbr(a * b);
			break;
	}
}

// =================== Exception ===================

const char *RPN::InvalidSpaceException::what() const throw()
{
	return "Invalid Space";
}

const char *RPN::ExpectedSpaceException::what() const throw()
{
	return "Expected a space";
};

const char *RPN::InvalidNumberException::what() const throw()
{
	return "Invalid Number";
};

const char *RPN::NotEnoughNumbersException::what() const throw()
{
	return "Not enough numbers on the stack";
};

const char *RPN::InvalidTokenException::what() const throw()
{
	return "Invalid token";
};

const char *RPN::DivisionByZeroException::what() const throw()
{
	return "Division by zero";
};

const char *RPN::MissingOperationsException::what() const throw()
{
	return "Missing operations";
};

const char *RPN::OverflowException::what() const throw()
{
	return "Int Overflow";
};