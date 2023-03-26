/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:44:45 by jtsizik           #+#    #+#             */
/*   Updated: 2023/03/25 11:00:05 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2) {
		std::cerr << "Error: Couldn't open the file" << std::endl;
		return (-1);
	}

	std::string filename = argv[1];
	std::ifstream db("data.csv");
	std::ifstream input(argv[1]);

	if (!db.is_open() || !input.is_open()) {
		std::cerr << "Error: Couldn't open the file" << std::endl;
		return (-1);
	}

	BitcoinExchange exchanger(db);
	exchanger.exchange(input);

	db.close();
	input.close();
	return (0);
}