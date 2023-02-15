/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:08:40 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/09 12:44:42 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat albert("Albert", 80); // will not throw an exception
		std::cout << albert << std::endl;

		// Bureaucrat donald("Donald", 151); //will throw an exception
		// std::cout << donald << std::endl;

		Bureaucrat ronaldo("Ronaldo", -1); //will throw an exception
		std::cout << ronaldo << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "---------------------------------" << std::endl;
	try
	{
		Bureaucrat albert("Albert", 2);
		albert.incrementGrade(); // will not throw an exception
		std::cout << albert << std::endl;
		albert.decrementGrade(); // will not throw an exception
		std::cout << albert << std::endl;

		// Bureaucrat donald("Donald", 150);
		// donald.decrementGrade(); //will throw an exception
		// std::cout << donald << std::endl;

		Bureaucrat ronaldo("ronaldo", 1);
		ronaldo.incrementGrade(); //will throw an exception
		std::cout << ronaldo << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}