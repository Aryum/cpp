/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 10:00:09 by ricsanto          #+#    #+#             */
/*   Updated: 2026/06/19 10:09:07 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#	define ITER_HPP

template <typename T, typename F>
void iter(T *arr, const int len, F function)
{
	for (int i = 0; i < len; i++)
		function(arr[i]);
}


#endif