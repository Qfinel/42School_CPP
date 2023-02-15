/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:04:02 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/02 18:06:10 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	commands[0] = "DEBUG";
	commands[1] = "INFO";
	commands[2] = "WARNING";
	commands[3] = "ERROR";

	funcs[0] = &Harl::debug;
	funcs[1] = &Harl::info;
	funcs[2] = &Harl::warning;
	funcs[3] = &Harl::error;
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
	for (int i = 0; i < 4; i++)
	{
		if (level == commands[i])
		{
			(this->*funcs[i])();
			return;
		}
	}
	std::cout << "\nInvalid command\n\n";
}