/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:08:40 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/09 12:54:54 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat albert("Albert", 80);
		Form sample("sample", 80, 80);
		albert.signForm(sample);
		std::cout << "---------------------------------" << std::endl;
		std::cout << albert << std::endl;
		std::cout << sample << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "---------------------------------" << std::endl;
	try
	{
		Bureaucrat albert("Albert", 80);
		Form sample("sample", 0, 80);
		albert.signForm(sample);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "---------------------------------" << std::endl;
	try
	{
		Bureaucrat albert("Albert", 80);
		Form sample("sample", 80, 151);
		albert.signForm(sample);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "---------------------------------" << std::endl;

	Bureaucrat albert("Albert", 81);
	Form sample("sample", 80, 80);
	albert.signForm(sample);
	std::cout << "---------------------------------" << std::endl;
	std::cout << albert << std::endl;
	std::cout << sample << std::endl;

	return 0;
}