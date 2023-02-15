/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:44:46 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/02 17:39:25 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->index = 0;
	this->total = 0;
	Contact contacts[8];
}
PhoneBook::~PhoneBook(){}

void	PhoneBook::addContact()
{
	if (this->index == 8)
		this->index = 0;
	
	Contact newContact;
	newContact.fillData();
	this->contacts[this->index] = newContact;
	this->index++;
	if (this->total < 8)
		this->total++;
}

void	PhoneBook::showContacts()
{
	std::string	line;
	int			j;

	std::cout << '\n';
	if (this->total == 0)
	{
		std::cout << "There are no contacts yet!\n\n";
		return;
	}
	for (int i = 1; i <= this->total; i++)
	{
		std::cout << "---------------------------------------------\n";
		std::cout << "|          |          |          |          |\n";
		std::cout << "|         " << i;
		this->contacts[i - 1].showColumns();
		std::cout << "|          |          |          |          |\n";
	}
	std::cout << "---------------------------------------------\n";

	std::cout << "\nPlease enter index of the contact to display ('EXIT' to exit)\n";
	while (1)
	{
		std::cout << "> ";
		std::getline(std::cin, line);
		if (line == "")
			continue;
		else if (line == "EXIT" || std::cin.eof())
			break;
		std::istringstream(line) >> j;
		if (j > this->total || j < 1)
			std::cout << "Invalid index\n";
		else
			this->contacts[j - 1].showData();
	}
}