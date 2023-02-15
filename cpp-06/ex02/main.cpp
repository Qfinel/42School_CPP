/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 12:28:10 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/10 13:04:43 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	srand((unsigned)time(NULL));
	int i = rand() % 3;
	switch (i)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		default:
			return (new C);
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Type: A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Type: B" << std::endl;
	else
		std::cout << "Type: C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A &some = dynamic_cast<A &>(p);
		(void)some;
		std::cout << "Type: A" << std::endl;
	}
	catch (std::bad_cast &bc)
	{
		(void)bc;
	}
	try
	{
		B &some = dynamic_cast<B &>(p);
		(void)some;
		std::cout << "Type: B" << std::endl;
	}
	catch (std::bad_cast &bc)
	{
		(void)bc;
	}
	try
	{
		C &some = dynamic_cast<C &>(p);
		(void)some;
		std::cout << "Type: C" << std::endl;
	}
	catch (std::bad_cast &bc)
	{
		(void)bc;
	}
}

int	main()
{
	Base *ptr;

	ptr = generate();
	std::cout << "-------------------------" << std::endl;
	identify(ptr);
	std::cout << "-------------------------" << std::endl;
	identify(*ptr);
	std::cout << "-------------------------" << std::endl;
	delete ptr;
	return 0;
}