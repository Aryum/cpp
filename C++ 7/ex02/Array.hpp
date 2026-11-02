/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 10:13:25 by ricsanto          #+#    #+#             */
/*   Updated: 2026/09/16 17:29:43 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#	define ARRAY_HPP


#include <exception>

template<typename T>
class Array
{
	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array& other);
		~Array();
		
		Array& operator=(const Array& other);
		T& operator[](unsigned int idx);
		const T& operator[](unsigned int idx) const;
		unsigned int size(void) const;

		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
	private:
		unsigned int _size;
		T *_arr;
};

#include "Array.tpp"

#endif