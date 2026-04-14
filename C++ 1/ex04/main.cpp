/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 21:22:09 by ricsanto          #+#    #+#             */
/*   Updated: 2026/02/25 10:47:09 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/header.h"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << RED << "Invalid number of arguments\n" << WHITE;
		return 1;
	}
	if (argv[2][0] == '\0')
	{
		std::cerr << RED << "Invalid target string\n" << WHITE;
		return 2;
	}

	std::string* file_str = get_file_str(argv[1]);
	if (file_str == NULL)
		return 3;
	
	std::string* newfile_str = replace_str(*file_str, argv[2],argv[3]);
	delete file_str;

	std::string name = std::string(argv[1]);
	name.append(".replace");
	std::ofstream outfile(name.c_str());
	if (!outfile)
	{
		std::cerr << RED << "Failed to create outfile\n" << WHITE;
		delete newfile_str;
		return 4;
	}
	outfile << *newfile_str << std::endl;
	delete newfile_str;
	return 0;
}
