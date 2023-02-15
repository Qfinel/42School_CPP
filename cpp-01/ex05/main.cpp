/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:02:43 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/02 18:16:53 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl newHarl;

	if (argc != 2)
		return (std::cout << "Invalid number of arguments\n", -1);

	newHarl.complain(argv[1]);
	return (0);
}