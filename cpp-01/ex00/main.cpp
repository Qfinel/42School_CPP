/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:05:27 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/01 13:12:50 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	*heapZombie;

	heapZombie = newZombie("Jim");
	heapZombie->announce();
	delete heapZombie; // Jim was destroyed here

	std::cout << '\n';
	randomChump("Johnny"); // Johnny was destroyed inside the function
	return (0);
}