/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 12:29:27 by jtsizik           #+#    #+#             */
/*   Updated: 2023/03/25 13:25:29 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()	{}

RPN::RPN(std::string &str)
{
	int result;
	for (std::string::iterator it = str.begin(); it != str.end(); it++)
	{
		if (std::isdigit(*it) && (*it - '0') > 9)
			throw std::runtime_error("Error");
		else if (std::isdigit(*it))
			_expr.push(*it - '0');
		else if (_expr.size() > 1)
		{
			if (*it == '+') {
				result = _expr.top();
				_expr.pop();
				result += _expr.top();
				_expr.pop();
			} else if (*it == '-') {
				result = _expr.top();
				_expr.pop();
				result = _expr.top() - result;
				_expr.pop();
			} else if (*it == '/') {
				result = _expr.top();
				_expr.pop();
				result = _expr.top() / result;
				_expr.pop();
			} else if (*it == '*') {
				result = _expr.top();
				_expr.pop();
				result *= _expr.top();
				_expr.pop();
			}
			if (*it != ' ')
				_expr.push(result);
		}
		else if (*it == ' ')
			continue;
		else
			throw std::runtime_error("Error");
	}
}

RPN::RPN(const RPN& src)	{*this = src;}

RPN &RPN::operator=(const RPN& src)
{
	this->_expr = src._expr;
	return (*this);
}

RPN::~RPN()	{}

void RPN::exec()
{
	if (_expr.size() == 1)
		std::cout << _expr.top() << std::endl;
	else
		throw std::runtime_error("Error");
}