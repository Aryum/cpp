/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 11:59:23 by ricsanto          #+#    #+#             */
/*   Updated: 2026/10/07 14:47:04 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cmath>

std::vector<int> PmergeMe::_vector = std::vector<int>();
std::deque<int> PmergeMe::_deque = std::deque<int>();
double PmergeMe::_vectorTime = 0;
double PmergeMe::_dequeTime = 0;
int PmergeMe::_comparisons = 0;


// =================== (Cons/Des)tructors ===================

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other) { (void) other; }
PmergeMe::~PmergeMe() {}

// =================== Operators ===================
PmergeMe& PmergeMe::operator=(const PmergeMe &other)
{
	(void)other;
	return *this;
}

// =================== Public ===================

void PmergeMe::Sort(int agrc, char **argv, bool debug)
{
	if (agrc == 1)
		throw NoArgsException();
	if (agrc - 1 > MAXCOUNT)
		throw TooManyNumbersException();
	std::vector<int> vector = std::vector<int>();

	_vector.clear();
	_deque.clear();
	for (int i = 1; i < agrc; i++)
	{
		char *end;
		long cur = std::strtol(argv[i], &end, 10);
		if (*end != '\0' || cur <= 0 || cur > INT_MAX)
			throw InvalidNumberException();
		_vector.push_back(cur);
		_deque.push_back(cur);
	}
	std::vector<int> before = _vector;
	if (debug)
	{
		SortPair_Dbg(0, 1);
		
		int sum = 0;
		for (int k = 1; k <= agrc - 1; ++k) 
		{
			double value = (3.0 / 4.0) * k;
			sum += static_cast<int>(ceil(log2(value)));
		}
		std::cout << WHITE << "Comparisons " << _comparisons << "\n";
		std::cout << WHITE << "Max " << sum << "\n";

	
		for (size_t i = 1; i < _vector.size(); i++)
		{
			if (_vector[i] < _vector[i - 1])
				throw std::runtime_error("Not sorted");
		}
		return ;
	}
	SortVector();
	SortDeque();
	for (size_t i = 1; i < _vector.size(); i++)
	{
		if (_vector[i] < _vector[i - 1])
			throw std::runtime_error("Not sorted");
		if (_deque[i - 1] != _vector[i - 1])
		{
			std::cout << "deque " << _deque[i - 1] << "\n";
			std::cout << "vector " << _vector[i - 1] << "\n";
			throw std::runtime_error("Vector and deque are not the same");
		}
	}
	Print_Vector(YELLOW, "Before: ", before);
	Print_Vector(BLUE, "After: ", _vector);

	std::cout << MAGENTA << "Time to process std::vector: " << _vectorTime << " us\n";
	std::cout << GREEN << "Time to process std::deque: " << _dequeTime << " us\n";

}


// =================== Exception ===================

const char *PmergeMe::InvalidNumberException::what() const throw()
{
	return "Invalid number";
}

const char *PmergeMe::TooManyNumbersException::what() const throw()
{
	return "Too many numbers";
}

const char *PmergeMe::NoArgsException::what() const throw()
{
	return "No arguments";
}
