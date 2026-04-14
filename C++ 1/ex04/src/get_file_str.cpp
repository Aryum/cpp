/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_str.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:45:13 by ricsanto          #+#    #+#             */
/*   Updated: 2026/01/06 15:04:56 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

std::string* get_file_str(char *filename)
{
	std::ifstream file(filename);
	if (!file)
	{
		std::cerr << RED << filename << " is not valid\n" << WHITE;
		return NULL;
	}

	std::string *ret = new std::string
	(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
	if (!file)
	{
		delete ret;
		std::cerr << RED << "Occured an error while reading "<< filename << "\n" << WHITE;
		return NULL;
	}
	return ret;
}