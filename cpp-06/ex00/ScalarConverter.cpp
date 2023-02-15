/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ScalarScalarConverterer.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:38:46 by jtsizik           #+#    #+#             */
/*   Updated: 2023/02/11 13:35:35 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() : str("0"), type("INT"){}

ScalarConverter::ScalarConverter(const std::string _str) : str(_str)
{
	this->a = 0;
	this->b = 0;
	this->c = 0;
	this->d = 0;

	if (this->str.length() == 1 && std::isprint(this->str[0]) && !std::isdigit(this->str[0]))
		this->type = "CHAR";
	else if ((std::isdigit(this->str[0]) || str[0] == '-' || str[0] == '+')
			&& this->str.find('.') == std::string::npos
			&& (std::isdigit(this->str[1])))
		this->type = "INT";
	else if (std::isdigit(this->str[0]) && this->str.length() == 1)
		this->type = "INT";
	else if ((std::isdigit(this->str[0]) || str[0] == '-' || str[0] == '+')
			&& this->str.find('.') != std::string::npos
			&& this->str.find('f') != std::string::npos)
		this->type = "FLOAT";
	else if (((std::isdigit(this->str[0]) || str[0] == '-' || str[0] == '+')
			&& this->str.find('.') != std::string::npos
			&& this->str.find('f') == std::string::npos))
		this->type = "DOUBLE";
	else if (this->str == "inff" || this->str == "nanf"
			|| this->str == "-inff" || this->str == "+inff"
			|| this->str == "inf" || this->str == "nan"
			|| this->str == "-inf" || this->str == "+inf"
			|| this->str == "-nan" || this->str == "+nan"
			|| this->str == "-nanf" || this->str == "+nanf")
		this->type = "DOUBLE";
	else
		throw ScalarConverter::WrongTypeException();

	if (this->type == "CHAR")
	{
		this->a = this->str[0];
		this->d = static_cast<double>(this->a);
	}	
	if (this->type == "INT")
		this->b = std::atoi(str.c_str());
	if (this->type == "FLOAT")
		this->c = std::atof(str.c_str());
	if (this->type != "CHAR")
		this->d = std::atof(str.c_str());
}

ScalarConverter &ScalarConverter::getConverter(const std::string _str)
{
	static ScalarConverter instance(_str);
    return instance;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	*this = src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	if (this == &src)
		return (*this);
	return (*this);
}

ScalarConverter::~ScalarConverter(){}

void	ScalarConverter::toChar()
{	
	if (this->type != "CHAR")
	{
		if (static_cast<int>(this->d) < 0 || static_cast<int>(this->d) > 127)
			std::cout << "char: impossible" << std::endl;
		else if (static_cast<int>(this->d) < 127 && static_cast<int>(this->d) > 32)
			std::cout << "char: " << static_cast<char>(this->d) << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: " << this->a << std::endl;
}

void	ScalarConverter::toInt()
{
	if (this->type != "INT")
	{
		if (this->d > 2147483647 || this->d < -2147483648
			|| this->str == "nan" || this->str == "nanf" || this->str == "-nan" || this->str == "-nanf"
			|| this->str == "+nan" || this->str == "+nanf")
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(this->d) << std::endl;
	}
	else
		std::cout << "int: " << this->b << std::endl;
}

void	ScalarConverter::toFloat() const
{
	std::cout << "float: " << static_cast<float>(this->d);
	if (this->d - static_cast<int>(this->d) == 0)
		std::cout << ".0";
	std::cout << 'f' << std::endl;
}

void	ScalarConverter::toDouble() const
{
	std::cout << "double: " << this->d;
	if (this->d - static_cast<int>(this->d) == 0)
		std::cout << ".0";
	std::cout << std::endl;
}

void	ScalarConverter::convert()
{
	toChar();
	toInt();
	toFloat();
	toDouble();
}

const char *ScalarConverter::WrongTypeException::what() const throw()
{
	return ("Exception: Wrong type provided! Should be int, char, float or double!");
}