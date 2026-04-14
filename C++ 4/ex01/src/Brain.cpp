/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:47:57 by ricsanto          #+#    #+#             */
/*   Updated: 2026/03/02 12:49:24 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/Brain.hpp"

// =================== (Cons/Des)tructors ===================

Brain::Brain() :
	_idea_count(0)
{
	_ideas_arr[0] = "Head empty no thoughs";
	std::cout << "Empty brain created\n";
}
Brain::Brain(const Brain& other) :
	_idea_count(other._idea_count)
{
	for (unsigned int i = 0; i < 100; i++)
	{
		if (i > other._idea_count)
			break ;
		_ideas_arr[i] = other._ideas_arr[i];
	}
	std::cout << "Brain was cloned\n";
}

Brain::~Brain()
{
	std::cout << "Brainrot hits another one\n";
}

// =================== Operators ===================

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		_idea_count = other._idea_count;
		for (unsigned int i = 0; i < 100; i++)
		{
			if (i > other._idea_count)
				break ;
			_ideas_arr[i] = other._ideas_arr[i];
		}
		std::cout << "Someone needs to get original ideas\n";
	}
	return *this;
}

// =================== Public ===================

void Brain::Add_Idea(std::string idea)
{
	_ideas_arr[_idea_count % 100] = idea;
	_idea_count++;
}

void Brain::Print_Ideas(void) const
{
	for (unsigned int i = 0; i < 100; i++)
	{
		if (i > _idea_count)
			break ;
		std::cout << "	" << _ideas_arr[i] << "\n";
	}
}