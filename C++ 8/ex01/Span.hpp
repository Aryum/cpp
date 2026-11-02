/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 11:05:12 by ricsanto          #+#    #+#             */
/*   Updated: 2026/09/22 16:10:45 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
# define SPAN_H

#include <exception>
#include <vector>
#include <climits>
#include <cstdlib>
#include <algorithm>

class Span
{
	public:
		Span();
		Span(unsigned int max);
		Span(const Span& other);
		~Span();
		Span &operator=(const Span& other);

		void addNumber(int number);
		template<typename T>
		void addRange(T start, T end);
		unsigned int shortestSpan(void) const;
		unsigned int longestSpan(void) const;
		
		class FullException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
		class EmptyException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
		class NotEnoughElementsException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
	private:
		unsigned int _maxCount;
		unsigned int _curCount;
		std::vector<int> _nbrs;
};

#include "Span.tpp"
#endif