/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_str.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:44:58 by ricsanto          #+#    #+#             */
/*   Updated: 2026/01/06 14:54:27 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

std::string* replace_str(std::string str, char *old_s, char *new_s)
{
	std::string *ret = new std::string();
	size_t last_pos = 0;
	size_t pos = 0;
	while (last_pos < str.length())
	{
		pos = str.find(old_s, last_pos);
		if (pos == std::string::npos)
			break;
		ret->append(str.substr(last_pos, pos - last_pos));
		ret->append(new_s);
		last_pos = pos + strlen(old_s);
	}
	ret->append(str.substr(last_pos, pos - last_pos));
	return ret;
}