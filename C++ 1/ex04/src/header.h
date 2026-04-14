/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:46:25 by ricsanto          #+#    #+#             */
/*   Updated: 2026/01/06 15:46:26 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#	define HEADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

#define WHITE "\033[0m"
#define GREEN "\033[1;32m"
#define MAGENTA "\033[1;35m"
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"

#define BUFFERSIZE 50

std::string* get_file_str(char *filename);
std::string* replace_str(std::string str, char *old_s, char *new_s);

#endif