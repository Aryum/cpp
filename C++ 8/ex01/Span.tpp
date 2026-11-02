/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 11:05:12 by ricsanto          #+#    #+#             */
/*   Updated: 2026/09/22 16:10:36 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

template <typename T>
void Span::addRange(T start, T end)
{
	while (start != end)
	{
		if (_curCount == _maxCount)
			throw Span::FullException();
		_nbrs.push_back(*start);
		_curCount++;
		start++;
	}
	std::sort(_nbrs.begin(), _nbrs.end());
}