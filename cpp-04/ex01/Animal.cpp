/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:39:48 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/06 17:55:04 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal constructor was called\n";
}

Animal::Animal(const Animal &src)
{
	std::cout << "Animal copy constructor was called\n";
	*this = src;
}

Animal &Animal::operator=(const Animal &src)
{
	std::cout << "Animal copy assignment operator was called\n";
	this->type = src.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor was called\n";
}


std::string	Animal::getType() const
{
	return (this->type);
}

void Animal::makeSound() const
{
	std::cout << "Some unrecognisable Animal sound...\n";
}

Brain *Animal::getBrain() const
{
	return (NULL);
}