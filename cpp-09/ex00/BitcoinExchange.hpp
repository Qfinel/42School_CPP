/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:44:39 by jtsizik           #+#    #+#             */
/*   Updated: 2023/03/25 12:38:05 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <limits>
# include <map>

struct Date {
	int year;
	int month;
	int day;
	std::string str;

	bool operator<(const Date& other) const {
        return ((year < other.year) || (year == other.year && month < other.month)
			|| (year == other.year && month == other.month && day < other.day));
    }
};

class BitcoinExchange
{
	private:
		std::map<Date, float>	_db;

		Date parseDate(std::string &date);
		void parseDb(std::ifstream &db_file);
		float getRate(Date date);
	public:
		BitcoinExchange();
		BitcoinExchange(std::ifstream &db_file);
		BitcoinExchange(const BitcoinExchange& src);
		BitcoinExchange &operator=(const BitcoinExchange& src);
		~BitcoinExchange();

		void exchange(std::ifstream &infile);
};

#endif