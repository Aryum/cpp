/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:38:44 by ricsanto          #+#    #+#             */
/*   Updated: 2026/09/16 17:31:31 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

// =================== (Cons/Des)tructors ===================

template<typename T>
Array<T>::Array(void) :
	_size(0)
{
	_arr = NULL;
}
template<typename T>
Array<T>::Array(unsigned int n) :
	_size(n)
{
	_arr = new T[n]();
}

template<typename T>
Array<T>::Array(const Array& other):
	_size(other._size)
{
	_arr = new T[other._size];
	for (unsigned int i = 0; i < other._size; i++)
		_arr[i] = other._arr[i];
}
template<typename T>
Array<T>::~Array()
{
	delete[] _arr;
}

// =================== Operators ===================

template<typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (&other != this)
	{
		Array<T> tmp = new T[other._size];
		for (unsigned int i = 0; i < other._size; i++)
			_arr[i] = other._arr[i];
		delete[] _arr;
		_arr = tmp;
		_size = other._size;
	}
	return *this;
}

template<typename T>
T& Array<T>::operator[](unsigned int idx)
{
	if (idx >= _size)
		throw OutOfBoundsException();
	return _arr[idx];
}

template<typename T>
const T& Array<T>::operator[](unsigned int idx) const
{
    if (idx >= _size)
        throw OutOfBoundsException();
    return _arr[idx];
}
// =================== Public ===================

template<typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

// =================== Exception ===================
template<typename T>
const char *Array<T>::OutOfBoundsException::what() const throw()
{
	return "Out of bounds";
};