/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 12:28:43 by jtsizik           #+#    #+#             */
/*   Updated: 2023/03/25 13:03:10 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <stack>

class RPN {
	private:
		std::stack<int>	_expr;
	public:
		RPN();
		RPN(std::string &str);
		RPN(const RPN& src);
		RPN &operator=(const RPN& src);
		~RPN();

		void exec();
};

#endif