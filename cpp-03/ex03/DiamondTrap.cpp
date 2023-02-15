/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:40:04 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/04 18:17:15 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	this->FragTrap::health = 100;
	this->ScavTrap::energy = 50;
	this->FragTrap::damage = 30;
	std::cout << "Default DiamondTrap constructor was called!\n";
}

DiamondTrap::DiamondTrap(std::string _name) : ClapTrap(_name + "_clap_name"), ScavTrap(), FragTrap()
{
	this->name = _name;
	this->FragTrap::health = 100;
	this->ScavTrap::energy = 50;
	this->FragTrap::damage = 30;
	std::cout << "DiamondTrap " << this->name << " was created!\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), ScavTrap(), FragTrap()
{
	std::cout << "Copy DiamondTrap constructor was called!\n";
	*this = src;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)
{
	std::cout << "Copy DiamondTrap assignment operator was called!\n";
	this->name = src.name;
	this->FragTrap::health = src.health;
	this->ScavTrap::energy = src.energy;;
	this->FragTrap::damage = src.damage;
	return (*this);
}

DiamondTrap::~DiamondTrap() {std::cout << "DiamondTrap " << this->name << " was destoyed!\n";}

void DiamondTrap::attack(const std::string& target)
{
	this->ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "My DiamondTrap name is: '" << this->name << "' but my ClapTrap name is: '" << this->ClapTrap::name << "'\n";
}