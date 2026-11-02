/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 09:22:59 by ricsanto          #+#    #+#             */
/*   Updated: 2026/06/22 10:48:47 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <exception>
#include <algorithm>

template<typename Container>
typename Container::const_iterator easyfind(const Container &c, int nbr);

class NotFoundException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

#include "easyfind.tpp"

#endif