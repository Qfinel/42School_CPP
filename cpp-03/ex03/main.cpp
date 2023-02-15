/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:53:51 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/04 18:13:25 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main()
{
	ClapTrap zombie("Zombie");
	ClapTrap vampire("Vampire");
	ClapTrap werewolf("Werewolf");

	zombie.attack("Vampire");
	vampire.attack("Werewolf");
	werewolf.attack("Zombie");

	zombie.takeDamage(0);
	vampire.takeDamage(7);
	werewolf.takeDamage(15);
	werewolf.takeDamage(2);

	zombie.beRepaired(0);
	vampire.beRepaired(2);
	werewolf.beRepaired(15);

	ClapTrap newVampire = vampire;
	newVampire.attack("Zombie");
	newVampire.attack("Zombie");
	newVampire.attack("Zombie");
	newVampire.attack("Zombie");
	newVampire.attack("Zombie");
	newVampire.attack("Zombie");
	newVampire.attack("Zombie");
	newVampire.attack("Zombie");
	newVampire.attack("Zombie");
	newVampire.beRepaired(1);

	ScavTrap robot("Robot");
	robot.attack("Zombie");
	robot.takeDamage(17);
	robot.beRepaired(2);
	robot.guardGate();

	FragTrap demon("Demon");
	demon.attack("Robot");
	demon.takeDamage(52);
	demon.beRepaired(93);
	demon.highFivesGuys();

	DiamondTrap god("God");
	god.attack("Demon");
	god.takeDamage(20);
	god.beRepaired(30);
	god.guardGate();
	god.highFivesGuys();
	god.whoAmI();
	return (0);
}