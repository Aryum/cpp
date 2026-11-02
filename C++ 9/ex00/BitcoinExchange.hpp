/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 09:23:23 by ricsanto          #+#    #+#             */
/*   Updated: 2026/06/26 15:18:49 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#	define BITCOINEXCHANGE_HPP

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

#include <iomanip>
#include <string>
#include <iostream>
#include <fstream>
#include <exception>
#include <map>
#include <cstring>
#include <climits>
#include <sstream>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		~BitcoinExchange();

		BitcoinExchange &operator=(const BitcoinExchange &other);

		void readDatabase(std::string fileName);

		class OpenFileErrorException : public std::exception
		{
			virtual const char *what() const throw();
		};
		
		class ReadFileErrorException : public std::exception
		{
			virtual const char *what() const throw();
		};
		
		class InvalidDateException : public std::exception
		{
			virtual const char *what() const throw();
		};

		class InvalidHeaderException : public std::exception
		{
			virtual const char *what() const throw();
		};
		
		class DataBaseErrorException : public std::exception
		{
			virtual const char *what() const throw();
		};
		
		private:
			void setData(void);
			void printError(std::string msg);
			void printOut(std::string date, float ammount, float value);
			std::map<time_t, float> _map;
};
#endif