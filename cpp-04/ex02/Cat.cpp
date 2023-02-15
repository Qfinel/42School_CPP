/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:46:17 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/06 18:26:56 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	this->myBrain = new Brain();
	std::cout << "Cat constructor was called\n";
}

Cat::Cat(const Cat &src)
{
	std::cout << "Cat copy constructor was called\n";
	*this = src;
}

Cat &Cat::operator=(const Cat &src)
{
	std::cout << "Cat copy assignment operator was called\n";
	this->type = src.type;
	*this->myBrain = *src.myBrain;
	return (*this);
}

Animal &Cat::operator=(const Animal &src)
{
	std::cout << "Cat copy assignment operator was called\n";
	this->type = src.getType();
	*this->myBrain = *(src.getBrain());
	return (*this);
}

Cat::~Cat()
{
	delete this->myBrain;
	std::cout << "Cat destructor was called\n";
}

void Cat::makeSound() const
{
	std::cout << "Meow!\n";
}

Brain *Cat::getBrain() const
{
	return (this->myBrain);
}