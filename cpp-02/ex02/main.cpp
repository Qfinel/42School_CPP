/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:10:30 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/03 16:53:13 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	// Fixed		c(Fixed(51.05f) / Fixed(24));
	// Fixed const d(Fixed(12) + Fixed(1.2324f));
	// std::cout << c << std::endl;
	// std::cout << --c << std::endl;
	// std::cout << ++c << std::endl;
	// std::cout << c-- << std::endl;
	// std::cout << c << std::endl;
	// std::cout << d << std::endl;
	// std::cout << Fixed( Fixed(c) - Fixed(d)) << std::endl;
	// std::cout << Fixed::min( c, d ) << std::endl;

	// std::cout << (c < d) << std::endl;
	// std::cout << (c > d) << std::endl;
	// std::cout << (c == d) << std::endl;
	// std::cout << (c != d) << std::endl;
	return 0;
}