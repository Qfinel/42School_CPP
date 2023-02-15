/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:17:27 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/06 14:46:21 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor was called\n";
}

Brain::Brain(const Brain &src)
{
	std::cout << "Brain copy constructor was called\n";
	*this = src;
}

Brain &Brain::operator=(const Brain &src)
{
	std::cout << "Brain copy assignment operator was called\n";
	for (int i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor was called\n";
}
