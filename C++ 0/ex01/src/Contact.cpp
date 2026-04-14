/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 17:01:51 by ricsanto          #+#    #+#             */
/*   Updated: 2026/02/23 15:28:10 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// =================== Helpers ===================

const char *Get_Prompt(Field field)
{
	switch (field)
	{
		case Field_FirstName:
			return("	First") ;
		case Field_LastName:
			return ("	Last");
		case Field_NickName:
			return ("	Nick");
		case Field_Secret:
			return ("Darkest Secret");
		default:
			return ("Phone Number");
	}
}
const char *Get_Color(Field field)
{
	if (field == Field_Secret)
		return MAGENTA;
	return GREEN;
}

bool Check_Name(const char *str)
	{
		for (size_t i = 0 ; str[i] != '\0'; i++)
		{
			if (isspace(str[i]))
				return false;
		}
		return true;
	}

bool Check_Number(const char *str)
{
	size_t i = 0;
	while (str[i] != '\0')
	{
		if (i > 9)
			return false;
		if (!isdigit(str[i]))
			return false;
		i++;
	}
	return i == 9;
}


// =================== Class ===================

Contact::Contact()
{
	_set = false;
}

Contact::~Contact(void)
{}

std::string& Contact::Get_Var_Ref(Field field)
{
	switch (field)
	{
		case Field_FirstName:
			return(_name_First);
		case Field_LastName:
			return (_name_Last);
		case Field_NickName:
			return (_name_Nick);
		case Field_Secret:
			return (_secret);
		default:
			return (_phoneNumber);
	}
}

std::string Contact::Get_Var_Val(Field field)
{
	return Get_Var_Ref(field);
}

bool Contact::IsSet(void)
{
	return _set;
}

void Contact::Set(void)
{
	_set = true;
}

void Contact::Change_Contact_Var(Field field)
{
	std::string& var = Get_Var_Ref(field);
	const char *prompt = Get_Prompt(field);
	const char *color  = Get_Color(field);
	const char *err_msg;
	bool (*check)(const char *) = NULL;
	
	switch (field)
	{
		case Field_PhoneNumber:
			err_msg = "Invalid Number";
			check = Check_Number;
			break;
		case Field_Secret:
			break ;
		default:
			err_msg = "Has spaces";
			check = Check_Name;
			break;
	}

	while (1)
	{
		std::cout << color << prompt << "	" << WHITE;
		std::getline(std::cin, var);
		if (std::cin.eof())
		{
			std::cout << RED << "\nEOF detected exiting\n" << WHITE;
			std::exit(0);
		}
		if (var.size() == 0)
			std::cout << RED << "Error: Cannot be empty!\n" << WHITE;
		else if (check != NULL && !check(var.c_str()))
			std::cout << RED << "Error: " << err_msg << "\n" << WHITE;
		else
			break;
	}
}