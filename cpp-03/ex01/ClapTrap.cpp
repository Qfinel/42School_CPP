/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:56:08 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/04 17:59:00 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->health = 10;
	this->energy = 10;
	this->damage = 0;
	std::cout << "Default ClapTrap constructor was called!\n";
}

ClapTrap::ClapTrap(std::string _name)
{
	this->name = _name;
	this->health = 10;
	this->energy = 10;
	this->damage = 0;
	std::cout << "ClapTrap " << this->name << " was created!\n";
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "Copy ClapTrap constructor was called!\n";
	*this = src;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	std::cout << "Copy ClapTrap assignment operator was called!\n";
	this->name = src.name;
	this->health = src.health;
	this->energy = src.energy;
	this->damage = src.damage;
	return (*this);
}

ClapTrap::~ClapTrap() {std::cout << "ClapTrap " << this->name << " was destoyed!\n";}

void ClapTrap::attack(const std::string& target)
{
	if (this->energy == 0)
		std::cout << "ClapTrap " << this->name << " has no more energy left!\n";
	else
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->damage << " points of damage!\n";
		this->energy--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->health == 0)
		std::cout << "ClapTrap " << this->name << "'s dead body receives " << amount << " points of damage! Please stop, he's already dead...\n";
	else if (this->health > amount)
	{
		this->health -= amount;
		std::cout << "ClapTrap " << this->name << " receives " << amount << " points of damage! Current hit points: " << this->health << std::endl;
	}
	else
	{
		this->health = 0;
		std::cout << "ClapTrap " << this->name << " receives " << amount << " points of damage and dies\n";
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy == 0)
		std::cout << "ClapTrap " << this->name << " has no more energy left!\n";
	else if (this->health == 0)
		std::cout << "ClapTrap " << this->name << " cannot repair himself, he is dead\n";
	else
	{
		this->energy--;
		this->health += amount;
		std::cout << "ClapTrap " << this->name << " repairs himself with " << amount << " hit points! Current hit points: " << this->health << std::endl;
	}
}