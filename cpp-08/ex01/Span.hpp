/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:32:32 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/11 15:24:36 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <vector>
# include <algorithm>
# include <iostream>

class Span
{
	private:
		unsigned int		N;
		std::vector<int>	vect;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &src);
		Span &operator=(const Span &src);
		~Span();

		void addNumber(int num);
		void addManyNumbers(int min, int max);
		int shortestSpan();
		int longestSpan();

	class SpanOverflowException : public std::exception
	{
		const char *what() const throw();
	};
	class TooFewNumsException : public std::exception
	{
		const char *what() const throw();
	};
};

#endif