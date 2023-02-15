/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:40:00 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/06 18:37:45 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# include "Brain.hpp"

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal &src);
		virtual Animal &operator=(const Animal &src) = 0;
		virtual ~Animal();

		std::string	getType() const;
		virtual void makeSound() const = 0;
		virtual Brain *getBrain() const = 0;
};

#endif