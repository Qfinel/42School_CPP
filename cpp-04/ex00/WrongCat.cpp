/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:55:51 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/06 13:13:00 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "WrongCat constructor was called\n";
}

WrongCat::WrongCat(const WrongCat &src)
{
	std::cout << "WrongCat copy constructor was called\n";
	*this = src;
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
	std::cout << "WrongCat copy assignment operator was called\n";
	this->type = src.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor was called\n";
}

void WrongCat::makeSound() const
{
	std::cout << "Meow!\n";
}