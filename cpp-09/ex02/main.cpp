/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:45:06 by jtsizik           #+#    #+#             */
/*   Updated: 2023/03/25 15:02:19 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: Not enough args" << std::endl;
		return (-1);
	}

	std::vector<std::string> arr;
	for (int i = 1; argv[i]; i++)
		arr.push_back(argv[i]);

	try
	{
		PmergeMe sorter(arr);
		sorter.sort();
	}
	catch (std::runtime_error &e)
	{
		std::cerr << e.what() << std::endl;
		return (-1);
	}
	return (0);
}