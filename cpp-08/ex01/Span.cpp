/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:32:50 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/11 15:29:08 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
	this->N = 10;
}

Span::Span(unsigned int N)
{
	this->N = N;
}

Span::Span(const Span &src)
{
	*this = src;
}

Span &Span::operator=(const Span &src)
{
	this->N = src.N;
	this->vect = src.vect;
	return (*this);
}

Span::~Span(){}

const char *Span::SpanOverflowException::what() const throw()
{
	return ("Exception! Already maximum numbers stored!");
}

const char *Span::TooFewNumsException::what() const throw()
{
	return ("Exception! Less than 2 numbers is stored!");
}

void	Span::addNumber(int num)
{
	if (this->vect.size() == this->N)
		throw Span::SpanOverflowException();

	this->vect.push_back(num);
}

void	Span::addManyNumbers(int min, int max)
{
	while (min <= max)
	{
		if (this->vect.size() == this->N)
			throw Span::SpanOverflowException();
		this->vect.push_back(min);
		min++;
	}
}	

int	Span::shortestSpan()
{
	if (this->vect.size() < 2)
		throw Span::TooFewNumsException();

	std::vector<int> copy = this->vect;
	std::sort(copy.begin(), copy.end());
	std::vector<int>::iterator it;
	int shortestSpan = *(copy.begin() + 1) - *copy.begin();

	for (it = copy.begin() + 1; it != copy.end() - 1; it++)
	{
		if ((*(it + 1) - *it) < shortestSpan)
			shortestSpan = *(it + 1) - *it;
	}
	return (shortestSpan);
}

int	Span::longestSpan()
{
	if (this->vect.size() < 2)
		throw Span::TooFewNumsException();

	int min = *std::min_element(this->vect.begin(), this->vect.end());
	int max = *std::max_element(this->vect.begin(), this->vect.end());

	return (max - min);
}