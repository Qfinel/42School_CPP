/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:00:07 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/01 17:13:55 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& newType)
{
	setType(newType);
}

Weapon::~Weapon(){}

void	Weapon::setType(const std::string& newType)
{
	if (newType == "")
	{
		std::cout << "Type can't be an empty string!!" << std::endl;
		return;
	}
	type = newType;
}

const std::string&	Weapon::getType()
{
	return (type);
}