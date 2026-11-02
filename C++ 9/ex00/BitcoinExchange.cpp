/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricsanto <ricsanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:38:44 by ricsanto          #+#    #+#             */
/*   Updated: 2026/10/12 12:04:57 by ricsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// =================== (Cons/Des)tructors ===================

BitcoinExchange::BitcoinExchange()
{
	setData();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) :
	_map(other._map)
{}

BitcoinExchange::~BitcoinExchange()
{}

// =================== Operators ===================

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (&other != this)
		_map = other._map;
	return *this;
}

// =================== Public ===================

void BitcoinExchange::readDatabase(std::string fileName)
{
	std::ifstream file(fileName.c_str());
	if (!file)
		throw OpenFileErrorException();

	std::string line;
	int i = 0;
	bool validHeader = false;
	while (std::getline(file, line))
	{
		if (i == 0)
		{
			if (line != "date | value")
				throw InvalidHeaderException();
			else 
				validHeader = true;
		}
		else
		{
			std::size_t pos = line.find(" | ");
			if (pos == std::string::npos)
			{
				printError("bad input => " + line);
				continue;
			}
			
			tm t;
			memset(&t, 0, sizeof(tm));
			std::string date = line.substr(0, pos).c_str();
			if(!strptime(date.c_str(), "%Y-%m-%d", &t))
			{
				printError("bad input => " + date);
				continue;
			}

			std::istringstream rate(line.substr(pos + 3));
			float ammount = 0;
			rate >> ammount;
			if (rate.fail() || !rate.eof())
			{
				printError("bad input => " + rate.str());
				continue;
			}
			if (ammount < 0.0f)
			{
				printError("not a positive number");
				continue;
			}
			if (ammount > 1000.0f)
			{
				printError("too large a number");
				continue;
			}
			
			time_t key = mktime(&t);
			std::map<time_t, float>::iterator it = _map.lower_bound(key);
			if(it != _map.end() && it->first == key)
				printOut(date, ammount, (*it).second * ammount);
			else if (it != _map.begin())
			{
				it--;
				printOut(date, ammount, (*it).second * ammount);
			}
			else
				printError("date is too early");
		}
		i++;
	}
	if (!validHeader)
		throw InvalidHeaderException();
	if (!file.eof())
		throw ReadFileErrorException();
	if (i == 1)
		printError("file has no entries");
	
}

// =================== Private ===================

void BitcoinExchange::printError(std::string msg)
{
	std::cerr << MAGENTA << "Error: "<< msg << WHITE << "\n";
}

void BitcoinExchange::printOut(std::string date, float ammount, float value)
{
	std::cout << BLUE << date << WHITE << " => " << ammount << " = " << value << "\n";
}
void BitcoinExchange::setData(void)
{
	std::ifstream file("data.csv");
	if (!file)
		throw DataBaseErrorException();

	std::string line;
	int i = 0;
	while (std::getline(file, line))
	{
		if (i == 0)
		{
			if(line != "date,exchange_rate")
				throw DataBaseErrorException();
			i++;
		}
		else
		{
			std::size_t pos = line.find(',');
			if (pos == std::string::npos)
				throw DataBaseErrorException();

			tm t;
			memset(&t, 0, sizeof(tm));
			if(!strptime(line.substr(0, pos).c_str(), "%Y-%m-%d", &t))
				throw DataBaseErrorException();

			std::istringstream rate(line.substr(pos + 1));
			float value = 0;
			rate >> value;
			if (rate.fail() || !rate.eof())
				throw DataBaseErrorException();
			
			std::size_t size = _map.size();
			_map.insert(std::make_pair(mktime(&t), value));
			if (size == _map.size())
				throw DataBaseErrorException();
		}
	}

	if (!file.eof())
		throw DataBaseErrorException();
}


// =================== Exception ===================

const char *BitcoinExchange::OpenFileErrorException::what() const throw()
{
	return "Problem in opening file";
}

const char *BitcoinExchange::ReadFileErrorException::what() const throw()
{
	return "Problem in reading file";
}

const char *BitcoinExchange::InvalidDateException::what() const throw()
{
	return "Invalid date format";
}

const char *BitcoinExchange::InvalidHeaderException::what() const throw()
{
	return "Invalid header";
}

const char *BitcoinExchange::DataBaseErrorException::what() const throw()
{
	return "Error processing database";
}