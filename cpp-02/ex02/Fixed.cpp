/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:29:58 by jtsizik           #+#    #+#             */
/*   Updated: 2023/01/27 14:34:49 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->value = 0;
}

Fixed::Fixed(const int num)
{
	this->value = num << this->bits;
}

Fixed::Fixed(const float num)
{
	this->value = roundf(num * (1 << this->bits));
}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	this->value = src.value;
	return (*this);
}

Fixed::~Fixed(){}

void Fixed::setRawBits( int const raw )
{
	this->value = raw;
}

int Fixed::getRawBits( void ) const
{
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

bool Fixed::operator>(const Fixed &src)
{
	return (this->value > src.value);
}

bool Fixed::operator<(const Fixed &src)
{
	return (this->value < src.value);
}

bool Fixed::operator>=(const Fixed &src)
{
	return (this->value >= src.value);
}

bool Fixed::operator<=(const Fixed &src)
{
	return (this->value <= src.value);
}

bool Fixed::operator==(const Fixed &src)
{
	return (this->value == src.value);
}

bool Fixed::operator!=(const Fixed &src)
{
	return (this->value != src.value);
}

Fixed	Fixed::operator+(const Fixed &src)
{
	Fixed	newNum;
	newNum.setRawBits(this->value + src.value);
	return (newNum);
}

Fixed	Fixed::operator-(const Fixed &src)
{
	Fixed	newNum;
	newNum.setRawBits(this->value - src.value);
	return (newNum);
}

Fixed	Fixed::operator*(const Fixed &src)
{
	Fixed	newNum;
	newNum.setRawBits((this->value * src.value));
	newNum.setRawBits(newNum.value / (1 << newNum.bits));
	return (newNum);
}

Fixed	Fixed::operator/(const Fixed &src)
{
	Fixed	newNum;
	newNum.setRawBits((this->value << newNum.bits) / src.value);
	return (newNum);
}

Fixed	&Fixed::operator++(void)
{
	this->setRawBits(this->value + 1);
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	this->setRawBits(this->value - 1);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed prev(*this);
	this->setRawBits(prev.value + 1);
	return (prev);
}

Fixed	Fixed::operator--(int)
{
	Fixed prev(*this);
	this->setRawBits(prev.value - 1);
	return (prev);
}

Fixed	&Fixed::min(Fixed &first, Fixed &second)
{
	if (first < second)
		return (first);
	else
		return (second);
}

Fixed	&Fixed::max(Fixed &first, Fixed &second)
{
	if (first > second)
		return (first);
	else
		return (second);
}

const Fixed	&Fixed::min(const Fixed &first, const Fixed &second)
{
	if (Fixed(first) < Fixed(second))
		return (first);
	else
		return (second);
}

const Fixed	&Fixed::max(const Fixed &first, const Fixed &second)
{
	if (Fixed(first) > Fixed(second))
		return (first);
	else
		return (second);
}

std::ostream &operator<<(std::ostream &ostream, const Fixed &obj)
{
	return (ostream << obj.toFloat());
}