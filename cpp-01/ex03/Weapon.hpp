/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:59:18 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/01 17:13:58 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	WEAPON_HPP
# define WEAPON_HPP
# include <iostream>
# include <string>

class	Weapon
{
	private:
		std::string	type;
	public:
		Weapon(const std::string& newType);
		~Weapon();

		const std::string& getType();
		void setType(const std::string& newtype);
};

#endif