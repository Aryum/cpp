/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 17:01:40 by ricsanto          #+#    #+#             */
/*   Updated: 2026/02/25 14:48:49 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#	define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

#include "Contact.hpp"

#define MAX_CONTACTS 8
#define VALID_PHONE 100000000
#define WHITE "\033[0m"
#define GREEN "\033[1;32m"
#define MAGENTA "\033[1;35m"
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void Add(void);
		void Search(void);
		
	private:
		Contact _contacts[MAX_CONTACTS];
		unsigned int _add_count;
};
#endif
