/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:46:17 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/06 13:06:06 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
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
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor was called\n";
}

void Cat::makeSound() const
{
	std::cout << "Meow!\n";
}