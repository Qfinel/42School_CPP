/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:30:13 by jtsizik           #+#    #+#             */
/*   Updated: 2023/01/27 14:34:53 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					value;
		static const int	bits = 8;
	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed &src);
		Fixed &operator=(const Fixed &src);
		~Fixed();

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		int		toInt( void ) const;
		float	toFloat( void ) const;

		bool	operator>(const Fixed &src);
		bool	operator<(const Fixed &src);
		bool	operator>=(const Fixed &src);
		bool	operator<=(const Fixed &src);
		bool	operator==(const Fixed &src);
		bool	operator!=(const Fixed &src);

		Fixed	operator+(const Fixed &src);
		Fixed	operator-(const Fixed &src);
		Fixed	operator*(const Fixed &src);
		Fixed	operator/(const Fixed &src);

		Fixed	&operator++(void);
		Fixed	&operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);

		static Fixed	&min(Fixed &first, Fixed &second);
		static Fixed	&max(Fixed &first, Fixed &second);
		static const Fixed	&min(const Fixed &first, const Fixed &second);
		static const Fixed	&max(const Fixed &first, const Fixed &second);
};

std::ostream	&operator<<(std::ostream &ostream, const Fixed &obj);
#endif