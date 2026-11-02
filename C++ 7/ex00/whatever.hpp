/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 09:50:51 by ricsanto          #+#    #+#             */
/*   Updated: 2026/06/19 09:58:01 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATERVER_HPP
#	define WHATERVER_HPP

template<typename T>
void swap(T &a , T &b)
{
	T c;

	c = a;
	a = b;
	b = c;
}

template<typename T>
T min (T a , T b)
{
	return (a < b ? a : b);
}

template<typename T>
T max (T a , T b)
{
	return (a > b ? a : b);
}

#endif