/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 12:04:54 by jtsizik           #+#    #+#             */
/*   Updated: 2023/02/11 15:01:22 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main()
{
	Data		sample;
	Data		*ptr;
	uintptr_t	check;

	sample.member = 42;
	std::cout << &sample << std::endl;
	check = Serializer::getSerializer().serialize(&sample);
	ptr = Serializer::getSerializer().deserialize(check);
	std::cout << ptr << std::endl; // identical to the previous one
	std::cout << ptr->member << std::endl; // value hasn't changed
	return 0;
}