/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:00:27 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/01 16:16:40 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	HUMAN_A_HPP
# define HUMAN_A_HPP
# include <iostream>
# include "Weapon.hpp"

class	HumanA
{
	private:
		std::string	_name;
		Weapon& _weapon;
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();

		void attack();
};

#endif