/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:38:29 by jtsizik           #+#    #+#             */
/*   Updated: 2023/02/11 14:12:12 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP
# include <iostream>
# include <cstdlib>

class  ScalarConverter
{
	private:
		const std::string	str;
		std::string			type;
		char				a;
		int					b;
		float				c;
		double				d;

		ScalarConverter();
		ScalarConverter(const std::string _str);
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter &operator=(const ScalarConverter &src);
		~ScalarConverter();

		void	toChar();
		void	toInt();
		void	toFloat() const;
		void	toDouble() const;

	public:
		static	ScalarConverter	&getConverter(const std::string _str);
		void	convert();

		class WrongTypeException : public std::exception
		{
			const char *what() const throw();
		};
};

#endif