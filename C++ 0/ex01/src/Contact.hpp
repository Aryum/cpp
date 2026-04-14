/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 17:01:49 by ricsanto          #+#    #+#             */
/*   Updated: 2026/02/24 14:30:51 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#	define CONTACT_HPP

#include <string>
#include <cstdlib>
#include <iostream>
#include <cstring>

#define WHITE "\033[0m"
#define GREEN "\033[1;32m"
#define MAGENTA "\033[1;35m"
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"

enum Field
{
	Field_FirstName,
	Field_LastName,
	Field_NickName,
	Field_Secret,
	Field_PhoneNumber
};

class Contact
{
	public:
		Contact(void);
		~Contact(void);
		bool IsSet(void);
		void Set(void);
		void Change_Contact_Var(Field field);
		std::string Get_Var_Val(Field field);

	private:
		std::string _name_First;
		std::string _name_Last;
		std::string _name_Nick;
		std::string _secret;
		std::string _phoneNumber;
		bool _set;
		std::string& Get_Var_Ref(Field field);

};

const char *Get_Prompt(Field field);
const char *Get_Color(Field field);
#endif