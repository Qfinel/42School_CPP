/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:32:06 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/06 18:33:45 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal *obj[10];

	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
		{
			obj[i] = new Cat();
			obj[i]->getBrain()->ideas[0] = "Cat idea";
		}
		else
		{
			obj[i] = new Dog();
			obj[i]->getBrain()->ideas[0] = "Dog idea";
		}
	}
	for (int i = 0; i < 10; i++)
		std::cout << obj[i]->getBrain()->ideas[0] << std::endl;

	std::cout << "-----------------------------------" << std::endl;
	std::cout << obj[2]->getBrain()->ideas[0] << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	(*obj[2]) = (*obj[7]);
	std::cout << obj[2]->getBrain()->ideas[0] << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	obj[7]->getBrain()->ideas[0] = "Random";
	std::cout << obj[2]->getBrain()->ideas[0] << std::endl; //should still print "Dog idea"
	std::cout << "-----------------------------------" << std::endl;

	for (int i = 0; i < 10; i++)
		delete obj[i];
	return 0;
}