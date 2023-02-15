/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:53:51 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/04 16:59:21 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

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
	return (0);
}