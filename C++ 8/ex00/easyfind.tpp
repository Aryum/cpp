/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 09:12:51 by ricsanto          #+#    #+#             */
/*   Updated: 2026/06/22 11:01:43 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template<typename Container>
typename Container::const_iterator easyfind(const Container &c, int nbr)
{
	typename Container::const_iterator it;
	it = std::find(c.begin(), c.end(), nbr);
	if (it == c.end())
		throw NotFoundException();
	return it;
}

const char *NotFoundException::what() const throw()
{
	return "Number not found on container";
};
