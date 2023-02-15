/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:48:08 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/10 15:01:00 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

static void	sampleIntFunc(int &i)
{
	i++;
}

static void sampleStringFunc(std::string &str)
{
	str.append("_str");
}

int main(void)
{
	int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	for (int i = 0; i < 10; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;
	::iter(arr, 10, sampleIntFunc);
	for (int i = 0; i < 10; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;

	std::cout << "-------------------------------" << std::endl;

	std::string arr1[5] = {"Hello", "World", "Test", "Something", "Random"};

	for (int i = 0; i < 5; i++)
		std::cout << arr1[i] << ' ';
	std::cout << std::endl;
	::iter(arr1, 5, sampleStringFunc);
	for (int i = 0; i < 5; i++)
		std::cout << arr1[i] << ' ';
	std::cout << std::endl;
	return 0;
}