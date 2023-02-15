/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:29:58 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/03 13:10:17 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	this->value = 0;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called\n";
	this->value = num << this->bits;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called\n";
	this->value = roundf(num * (1 << this->bits));
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called\n";
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called\n";
	this->value = src.value;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called\n";
	this->value = raw;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return (this->value);
}

float	Fixed::toFloat( void ) const
{
	return ((float)this->value / (float)(1 << this->bits));
}

int	Fixed::toInt( void ) const
{
	return (this->value >> this->bits);
}

std::ostream &operator<<(std::ostream &ostream, const Fixed &obj)
{
	return (ostream << obj.toFloat());
}