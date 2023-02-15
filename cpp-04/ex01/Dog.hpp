/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:46:53 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/06 18:33:07 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"

class Dog : public Animal
{
	private:
		Brain *myBrain;
	public:
		Dog();
		Dog(const Dog &src);
		Dog &operator=(const Dog &src);
		Animal &operator=(const Animal &src);
		~Dog();

		void makeSound() const;
		Brain *getBrain() const;
};

#endif