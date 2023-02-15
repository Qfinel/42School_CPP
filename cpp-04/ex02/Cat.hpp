/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:46:31 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/06 18:33:04 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"

class Cat : public Animal
{
	private:
		Brain *myBrain;
	public:
		Cat();
		Cat(const Cat &src);
		Cat &operator=(const Cat &src);
		Animal &operator=(const Animal &src);
		~Cat();

		void makeSound() const;
		Brain *getBrain() const;
};

#endif