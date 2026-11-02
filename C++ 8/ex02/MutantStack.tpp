/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:38:44 by ricsanto          #+#    #+#             */
/*   Updated: 2026/09/16 11:15:12 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

// =================== (Cons/Des)tructors ===================
template <typename T, typename C>
MutantStack<T,C>::MutantStack() :
	std::stack<T, C>()
{}

template <typename T, typename C>
MutantStack<T,C>::MutantStack(const MutantStack<T,C>& other) :
	std::stack<T, C>(other)
{}
template <typename T, typename C>
MutantStack<T,C>::~MutantStack() 
{}

// =================== Operators ===================

template <typename T, typename C>
MutantStack<T,C>& MutantStack<T,C>::operator=(const MutantStack& other)
{
	if (&other != this)
		std::stack<T,C>::operator=(other);
	return *this;
}

// =================== Public ===================

template <typename T, typename C>
typename MutantStack<T,C>::iterator MutantStack<T,C>::begin(void)
{
	return this->c.begin();
}

template <typename T, typename C>
typename MutantStack<T,C>::iterator MutantStack<T,C>::end(void)
{
	return this->c.end();
}

template <typename T, typename C>
typename MutantStack<T,C>::const_iterator MutantStack<T,C>::begin(void) const
{
	return this->c.begin();
}

template <typename T, typename C>
typename MutantStack<T,C>::const_iterator MutantStack<T,C>::end(void) const
{
	return this->c.end();
}