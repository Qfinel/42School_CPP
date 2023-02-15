/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:47:54 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/04 17:59:33 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->health = 100;
	this->energy = 50;
	this->damage = 20;
	std::cout << "Default ScavTrap constructor was called!\n";
}

ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name)
{
	this->name = _name;
	this->health = 100;
	this->energy = 50;
	this->damage = 20;
	std::cout << "ScavTrap " << this->name << " was created!\n";
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
	std::cout << "Copy ScavTrap constructor was called!\n";
	*this = src;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << "Copy ScavTrap assignment operator was called!\n";
	this->name = src.name;
	this->health = src.health;
	this->energy = src.energy;
	this->damage = src.damage;
	return (*this);
}

ScavTrap::~ScavTrap() {std::cout << "ScavTrap " << this->name << " was destoyed!\n";}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " is now in a Gate keeper mode!\n";
}

void ScavTrap::attack(const std::string& target)
{
	if (this->energy == 0)
		std::cout << "ScavTrap " << this->name << " has no more energy left!\n";
	else
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->damage << " points of damage!\n";
		this->energy--;
	}
}