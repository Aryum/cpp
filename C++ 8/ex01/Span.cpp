/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:38:44 by ricsanto          #+#    #+#             */
/*   Updated: 2026/09/22 16:10:34 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// =================== (Cons/Des)tructors ===================

Span::Span() :
	_maxCount(0),
	_curCount(0),
	_nbrs(0)
{}

Span::Span(unsigned int max) :
	_maxCount(max),
	_curCount(0)
{
	_nbrs.reserve(max);
}

Span::Span(const Span& other) :
	_maxCount(other._maxCount),
	_curCount(other._curCount),
	_nbrs(other._nbrs)
{}

Span::~Span() 
{}

// =================== Operators ===================

Span& Span::operator=(const Span& other)
{
	if (&other != this)
	{
		_maxCount = other._maxCount;
		_curCount = other._curCount;
		_nbrs = other._nbrs;
	}
	return *this;
}

// =================== Public ===================

void Span::addNumber(int number)
{
	if (_curCount == _maxCount)
		throw Span::FullException();
	_nbrs.push_back(number);
	std::sort(_nbrs.begin(), _nbrs.end());
	_curCount++;
}


unsigned int Span::shortestSpan(void) const
{
	if (_curCount < 2)
		throw NotEnoughElementsException();
	unsigned int ret = UINT_MAX;
	unsigned int tmp = 0;
	unsigned int i = 0;
	while (i + 1 < _curCount)
	{
		tmp = _nbrs.at(i + 1) - _nbrs.at(i);
		if (tmp < ret)
			ret = tmp;
		i++;
	}
	return (ret);
}

unsigned int Span::longestSpan(void) const
{
	if (_curCount < 2)
		throw NotEnoughElementsException();
	return static_cast<unsigned int>(_nbrs[_nbrs.size() - 1] - _nbrs[0]);
}


// =================== Exception ===================

const char *Span::FullException::what() const throw()
{
	return "Span is full";
}

const char *Span::EmptyException::what() const throw()
{
	return "Span is empty";
}

const char *Span::NotEnoughElementsException::what() const throw()
{
	return "Span doesn't have enough elements";
}
