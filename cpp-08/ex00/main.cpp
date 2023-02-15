/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:01:35 by jtsizik           #+#    #+#             */
/*   Updated: 2023/02/14 12:56:56 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main()
{
	std::vector<int> vect;
	for (int i = 0; i < 10; i++)
		vect.push_back(i);

	std::vector<int>::const_iterator it;
	for (it = vect.begin(); it != vect.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;

	if (easyfind(vect, 6))
		std::cout << "Found!" << std::endl;
	else
		std::cout << "Not found!" << std::endl;
	if (easyfind(vect, 10))
		std::cout << "Found!" << std::endl;
	else
		std::cout << "Not found!" << std::endl;
	return 0;
}