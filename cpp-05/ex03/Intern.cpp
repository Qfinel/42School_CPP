/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:31:37 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/09 15:53:17 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern &src)
{
	*this = src;
}

Intern &Intern::operator=(const Intern &src)
{
	if (this == &src)
		return (*this);
	return (*this);
}

Intern::~Intern(){}

AForm *Intern::makeForm(std::string name, std::string target)
{
	int i = 0;
	std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	while (i < 3)
	{
		if (name == names[i])
		{
			std::cout << "Intern creates " << name << " form" << std::endl;
			break;
		}
		i++;
	}

	switch (i)
	{
		case 0:
			return (new ShrubberyCreationForm(target));
		case 1:
			return (new RobotomyRequestForm(target));
		case 2:
			return (new PresidentialPardonForm(target));
		default:
			std::cout << "Requested form doesn't exist" << std::endl;
	}
	return (NULL);
}