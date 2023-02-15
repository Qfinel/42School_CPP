/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:47:08 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/06 18:26:58 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	this->myBrain = new Brain();
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
	*this->myBrain = *src.myBrain;
	return (*this);
}

Animal &Dog::operator=(const Animal &src)
{
	std::cout << "Dog copy assignment operator was called\n";
	this->type = src.getType();
	*this->myBrain = *(src.getBrain());
	return (*this);
}

Dog::~Dog()
{
	delete this->myBrain;
	std::cout << "Dog destructor was called\n";
}

void Dog::makeSound() const
{
	std::cout << "Bark!\n";
}

Brain *Dog::getBrain() const
{
	return (this->myBrain);
}