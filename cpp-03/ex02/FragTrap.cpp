/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:22:00 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/04 17:59:53 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->health = 100;
	this->energy = 100;
	this->damage = 30;
	std::cout << "Default FragTrap constructor was called!\n";
}

FragTrap::FragTrap(std::string _name) : ClapTrap(_name)
{
	this->name = _name;
	this->health = 100;
	this->energy = 100;
	this->damage = 30;
	std::cout << "FragTrap " << this->name << " was created!\n";
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
	std::cout << "Copy FragTrap constructor was called!\n";
	*this = src;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	std::cout << "Copy FragTrap assignment operator was called!\n";
	this->name = src.name;
	this->health = src.health;
	this->energy = src.energy;
	this->damage = src.damage;
	return (*this);
}

FragTrap::~FragTrap() {std::cout << "FragTrap " << this->name << " was destoyed!\n";}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->name << " highs five to everyone!\n";
}