/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:42:25 by ricsanto          #+#    #+#             */
/*   Updated: 2026/01/16 16:34:25 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#	define BRAIN_HPP

#include <string>
#include <iostream>
#include "Color.hpp"

class Brain
{
	public:
		Brain();
		Brain(const Brain& other);
		~Brain();

		Brain& operator=(const Brain& other);
		void Add_Idea(const std::string idea);
		void Print_Ideas(void) const;

	private:
		unsigned int _idea_count;
		std::string _ideas_arr[100];
};
#endif