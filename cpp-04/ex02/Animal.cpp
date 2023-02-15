/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:39:48 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/06 18:41:21 by jtsizik          ###   ########.fr       */
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

Animal::~Animal()
{
	std::cout << "Animal destructor was called\n";
}

std::string	Animal::getType() const
{
	return (this->type);
}
