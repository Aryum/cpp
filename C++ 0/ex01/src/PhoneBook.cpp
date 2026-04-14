/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 17:01:37 by ricsanto          #+#    #+#             */
/*   Updated: 2026/02/24 14:25:08 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// =================== Helpers ===================

void print_info(Contact contact, Field field)
{
	std::cout << Get_Color(field) << Get_Prompt(field) << "	" << WHITE; 
	std::cout << contact.Get_Var_Val(field) << "\n";
}

void print_row(std::string val)
{
	if (val.length() >= 10)
		std::cout << val.substr(0,9) << ".";
	else
		std::cout << std::setw(10) << val ;
	std::cout << " | ";
}

// =================== Class ===================

// =================== Constructors ===================

PhoneBook::PhoneBook(void)
{
	_add_count = 0;
}

PhoneBook::~PhoneBook(void)
{
}

// =================== Public ===================

void PhoneBook::Add(void)
{
	std::cout << "\n";
	unsigned int cur = _add_count % MAX_CONTACTS;
	if (_contacts[cur].IsSet())
		std::cout << YELLOW << "Phonebook full! Writing over a previous entry\n" << WHITE;
	_contacts[cur].Set();
	_contacts[cur].Change_Contact_Var(Field_PhoneNumber);
	std::cout << BLUE << "Names\n" << WHITE;
	_contacts[cur].Change_Contact_Var(Field_FirstName);
	_contacts[cur].Change_Contact_Var(Field_LastName);
	_contacts[cur].Change_Contact_Var(Field_NickName);
	_contacts[cur].Change_Contact_Var(Field_Secret);
	_add_count++;
}


void PhoneBook::Search(void)
{
	if (_add_count == 0)
	{
		std::cout << RED << "Error: Phonebook is empty\n" << WHITE;
		return ;
	}
	std::cout << "\n";
	std::cout << "Idx" << "|";
	print_row("Number");
	print_row("First");
	print_row("Last");
	print_row("Nick");
	std::cout << "\n";
	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		if (!_contacts[i].IsSet())
			break ;
		std::cout << i + 1 << std::setw(3) << "|";
		print_row(_contacts[i].Get_Var_Val(Field_PhoneNumber));
		print_row(_contacts[i].Get_Var_Val(Field_FirstName));
		print_row(_contacts[i].Get_Var_Val(Field_LastName));
		print_row(_contacts[i].Get_Var_Val(Field_NickName));
		std::cout << "\n";
	}
	
	int index;
	while (1)
	{
		std::string line;
		std::cout << "Contact index: ";
		std::getline(std::cin, line);
		index = atoi(line.c_str());
		if (index > 0 && index < MAX_CONTACTS && _contacts[index - 1].IsSet())
			break ;
		else
			std::cout << RED << "Error: Insert valid index\n" << WHITE;
	}
	index--;
	print_info(_contacts[index], Field_PhoneNumber);
	std::cout << BLUE << "Names\n" << WHITE;
	print_info(_contacts[index], Field_FirstName);
	print_info(_contacts[index], Field_LastName);
	print_info(_contacts[index], Field_NickName);
	print_info(_contacts[index], Field_Secret);
}
