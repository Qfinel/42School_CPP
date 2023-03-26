/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:44:41 by jtsizik           #+#    #+#             */
/*   Updated: 2023/03/25 12:38:19 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()	{}

BitcoinExchange::BitcoinExchange(std::ifstream &db_file)
{
	parseDb(db_file);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)	{*this = src;}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange& src)
{
	this->_db = src._db;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

Date BitcoinExchange::parseDate(std::string &date)
{
	Date parsed;

	// Trim
	size_t pos = date.find_first_not_of(" \n\t\r\v\f");
	date.erase(0, pos); // Remove from beggining
	pos = date.find_first_of(" \n\t\r\v\f");
	if (pos != std::string::npos)
		date.erase(pos); // Remove from the end

	if (date.size() != 10)
		throw (std::runtime_error("Error: bad input"));

	parsed.year = std::atoi(date.substr(0, 4).c_str());
	parsed.month = std::atoi(date.substr(5, 2).c_str());
	parsed.day = std::atoi(date.substr(8, 2).c_str());

	if (!(parsed.month > 0 && parsed.month < 13 && parsed.day > 0 && parsed.day < 32 && date[4] == '-'
		&& date[7] == '-' && date.find_first_not_of("1234567890-") == std::string::npos))
		throw (std::runtime_error("Error: bad input"));

	parsed.str = date;
	return (parsed);
}

void BitcoinExchange::parseDb(std::ifstream &db_file)
{
	std::string line;
	std::string left;
	std::string right;
	Date	date;
	float	value;

	while (std::getline(db_file, line))
	{
		left = line.substr(0, line.find_first_of(','));
		right = line.substr(line.find_first_of(',') + 1);

		value = std::atof(right.c_str());

		try
		{
			date = parseDate(left);
			this->_db[date] = value;
		}
		catch (std::runtime_error &e)
		{
			continue ;
		}
	}
}

float BitcoinExchange::getRate(Date date)
{
	std::map<Date, float>::iterator	it;
	it = _db.lower_bound(date);
	if (it == _db.begin() && it->first.str != date.str)
		throw std::runtime_error("Error: no data");
	return (it->second);
}

void BitcoinExchange::exchange(std::ifstream &infile)
{
	size_t		pos;
	std::string	line;
	std::string	left;
	std::string	right;
	Date		date;
	float		value;

	std::getline(infile, line); // skip first line

	while (std::getline(infile, line))
	{
		if (line.empty())
			continue ;

		left = line.substr(0, line.find_first_of(" "));
		right = line.substr(line.find_first_of('|') + 1);

		pos  = right.find_first_not_of(" \n\t\r\v\f");
		right.erase(0, pos); // Remove from beggining
		pos = right.find_first_of(" \n\t\r\v\f");
		if (pos != std::string::npos)
			right.erase(pos); // Remove from the end

		value = std::atof(right.c_str());

		try
		{
			date = parseDate(left);
			getRate(date);

			// CHECKING
			if (right.find_first_not_of("1234567890-.") != std::string::npos || line.find('|') == std::string::npos || right == "")
				std::cerr << "Error: bad value input." << std::endl;
			else if (value < 0.0)
				std::cerr << "Error: not a positive number." << std::endl;
			else if (right.size() > 9)
				std::cerr << "Error: too large a number." << std::endl;
			else
				std::cout << date.str << " => " << value << " = " << value * getRate(date) << std::endl;
		}
		catch (std::runtime_error &e)
		{
			std::cerr << e.what() << " => " << left << std::endl;
		}
	}
}