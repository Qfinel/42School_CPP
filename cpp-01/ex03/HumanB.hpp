/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:01:12 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/01 16:38:30 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	HUMAN_B_HPP
# define HUMAN_B_HPP
# include <iostream>
# include "Weapon.hpp"

class	HumanB
{
	private:
		std::string	_name;
		Weapon	*_weapon;
	public:
		HumanB(std::string name);
		~HumanB();

		void setWeapon(Weapon &weapon);
		void attack();
};

#endif