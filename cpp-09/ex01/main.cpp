/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 12:28:26 by jtsizik           #+#    #+#             */
/*   Updated: 2023/03/25 13:25:39 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Wrong number of arguments" << std::endl;
		return (-1);
	}

	try
	{
		std::string notation(argv[1]);
		RPN reverser(notation);
		reverser.exec();
	}
	catch (std::runtime_error &e)
	{
		std::cerr << e.what() << std::endl;
		return (-1);
	}
	return (0);
}