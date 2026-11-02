/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 13:35:02 by ricsanto          #+#    #+#             */
/*   Updated: 2026/06/22 15:23:37 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template <typename T, typename C = std::deque<T> >
class MutantStack : 
	public std::stack<T, C>
{
	public:
		MutantStack(void);
		MutantStack(const MutantStack& other);
		~MutantStack(void);
		MutantStack& operator=(const MutantStack& other);
	
		typedef typename C::iterator iterator;
		iterator begin(void);
		iterator end(void);

		typedef typename C::const_iterator const_iterator;
		const_iterator begin(void) const;
		const_iterator end(void) const;
};

#include "MutantStack.tpp"
#endif