/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:06:49 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/01 14:40:18 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie	*newHorde;

	if (N < 1)
	{
		std::cout << "Invalid number of zombies!\n";
		return (NULL);
	}
	newHorde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		newHorde[i].giveName(name);
		newHorde[i].announce();
	}
	return (newHorde);
}