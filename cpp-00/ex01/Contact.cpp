/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:40:18 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/09 15:57:02 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){}
Contact::~Contact(){}

void	Contact::showColumns()
{
	std::cout << "|";
	for (int i = 0; i < (10 - (int)this->firstname.length()); i++)
		std::cout << " ";
	if (this->firstname.length() > 10)
		std::cout << this->firstname.substr(0, 9) << '.';
	else
		std::cout << this->firstname;
	std::cout << "|";
	for (int i = 0; i < (10 - (int)this->lastname.length()); i++)
		std::cout << " ";
	if (this->lastname.length() > 10)
		std::cout << this->lastname.substr(0, 9) << '.';
	else
		std::cout << this->lastname;
	std::cout << "|";
	for (int i = 0; i < (10 - (int)this->nickname.length()); i++)
		std::cout << " ";
	if (this->nickname.length() > 10)
		std::cout << this->nickname.substr(0, 9) << '.';
	else
		std::cout << this->nickname;
	std::cout << "|\n";
}


void	Contact::showData()
{
	std::cout << "\nFirst name: " << this->firstname;
	std::cout << "\nLast name: " << this->lastname;
	std::cout << "\nNickname: " << this->nickname;
	std::cout << "\nPhone number: " << this->number;
	std::cout << "\nDarkest secret: " << this->secret;
	std::cout << "\n\n";
}

namespace	{
	bool	checkIsAlpha(std::string str)
	{
		if (str == "")
			return false;
		for (std::string::iterator ptr = str.begin(); ptr != str.end(); ptr++)
		{
			if (!std::isalpha(*ptr))
				return false;
		}
		return true;
	}

	bool	checkIsNum(std::string str)
	{
		if (str == "")
			return false;
		for (std::string::iterator ptr = str.begin(); ptr != str.end(); ptr++)
		{
			if (!std::isdigit(*ptr))
				return false;
		}
		return true;
	}
}

void	Contact::fillData()
{
	std::cout << '\n';
	while (1)
	{
		std::cout << "FIRST NAME: ";
		std::getline(std::cin, this->firstname);
		if (!checkIsAlpha(this->firstname))
			std::cout << "Invalid first name\n";
		else
			break ;
	}
	while (1)
	{
		std::cout << "LAST NAME: ";
		std::getline(std::cin, this->lastname);
		if (!checkIsAlpha(this->lastname))
			std::cout << "Invalid last name\n";
		else
			break ;
	}
	while (1)
	{
		std::cout << "NICKNAME: ";
		std::getline(std::cin, this->nickname);
		if (!checkIsAlpha(this->nickname))
			std::cout << "Invalid nickname\n";
		else
			break ;
	}
	while (1)
	{
		std::cout << "PHONE NUMBER: ";
		std::getline(std::cin, this->number);
		if (!checkIsNum(this->number))
			std::cout << "Invalid phone number\n";
		else
			break ;
	}
	while (1)
	{
		std::cout << "DARKEST SECRET: ";
		std::getline(std::cin, this->secret);
		if (this->secret != "")
			break;
	}
	std::cout << "\nContact is successfully added!\n" << std::endl;
}