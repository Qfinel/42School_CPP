/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:32:06 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/07 10:58:29 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	Animal* dog = new Dog();
	Animal* cat = new Cat();
	// Animal* animal = new Animal();

	dog->makeSound();
	cat->makeSound();

	delete dog;
	delete cat;
	return 0;
}
