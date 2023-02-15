/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:47:08 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/06 13:06:03 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog constructor was called\n";
}

Dog::Dog(const Dog &src)
{
	std::cout << "Dog copy constructor was called\n";
	*this = src;
}

Dog &Dog::operator=(const Dog &src)
{
	std::cout << "Dog copy assignment operator was called\n";
	this->type = src.type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor was called\n";
}

void Dog::makeSound() const
{
	std::cout << "Bark!\n";
}