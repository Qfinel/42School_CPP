/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:41:09 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/01 14:56:07 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string 	text = "HI THIS IS BRAIN";
	std::string		*stringPTR = &text;
	std::string&	stringREF = text;	

	std::cout << "\nMemory address of the 'text' variable: " << &text;
	std::cout << "\nMemory address held by stringPTR: " << &stringPTR;
	std::cout << "\nMemory address held by stringREF: " << &stringREF;
	std::cout << "\n";
	std::cout << "\nValue of the 'text' variable: " << text;
	std::cout << "\nValue pointed to by stringPTR: " << stringPTR;
	std::cout << "\nValue pointed to by stringREF: " << stringREF;
	std::cout << "\n\n";
	return (0);
}