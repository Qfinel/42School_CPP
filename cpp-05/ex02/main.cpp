/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:08:40 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/09 15:30:17 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	try
	{
		Bureaucrat albert("Albert", 145);
		Bureaucrat karl("Karl", 137);
		ShrubberyCreationForm paper("something"); // to sign 145, to execute 137
		// RobotomyRequestForm paper("something"); // to sign 72, to execute 45
		// PresidentialPardonForm paper("something"); // to sign 25, to execute 5

		std::cout << paper << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
		albert.signForm(paper);
		std::cout << "-----------------------------------------" << std::endl;
		std::cout << paper << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
		karl.executeForm(paper);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}