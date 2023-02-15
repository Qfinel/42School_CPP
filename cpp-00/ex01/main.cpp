/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:23:45 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/09 15:59:04 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int	main(void)
{
	std::string	line;
	PhoneBook	newPhoneBook;

	std::cout << "\nPhoneBook started\nPlease provide a command: 'ADD', 'SEARCH' or 'EXIT'\n" << std::endl;
	while (1)
	{
		std::cout << "PhoneBook> ";
		std::getline(std::cin, line);
		if (line == "ADD")
			newPhoneBook.addContact();
		else if (line == "SEARCH")
			newPhoneBook.showContacts();
		else if (line == "EXIT" || std::cin.eof())
			break;
		else if (line == "")
			continue;
		else
			std::cout << "Invalid command" << std::endl;
	}
	return (0);
}