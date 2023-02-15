/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:04:02 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/02 18:18:12 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	commands[0] = "DEBUG";
	commands[1] = "INFO";
	commands[2] = "WARNING";
	commands[3] = "ERROR";
}

Harl::~Harl(){}

void	Harl::debug()
{
	std::cout << "\n(DEBUG)\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n\n";
}

void	Harl::info()
{
	std::cout << "\n(INFO)\n";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n\n";
}

void	Harl::warning()
{
	std::cout << "\n(WARNING)\n";
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n\n";
}

void	Harl::error()
{
	std::cout << "\n(ERROR)\n";
	std::cout << "This is unacceptable! I want to speak to the manager now.\n\n";
}

void	Harl::complain(std::string level)
{
	int	i = 0;

	while (i < 4)
	{
		if (level == commands[i])
			break;
		i++;
	}

	switch (i)
	{
		case 0:
			debug();
		case 1:
			info();
		case 2:
			warning();
		case 3:
			error();
			break;
		default:
			std::cout << "\nInvalid command\n\n";
	}
}