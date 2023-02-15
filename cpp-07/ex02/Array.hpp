/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:11:19 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/10 15:52:56 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>

template <typename T>
class Array
{
	private:
		T				*arr;
		unsigned int	arrSize;
	public:
		Array(){this->arr = new T[0]; this->arrSize = 0;}
		Array(unsigned int n){this->arr = new T[n]; this->arrSize = n;}
		Array(const Array &src){*this = src;}
		Array &operator=(const Array &src)
		{
			this->arr = new T[src.size()];
			this->arrSize = src.size();
			for (int i = 0; i < (int)this->arrSize; i++)
				this->arr[i] = src.arr[i];
			return (*this);
		}
		~Array(){delete [] this->arr;}

		T	&operator[](const unsigned int &index)
		{
			if (index >= 0 && index < this->arrSize)
				return (arr[index]);
			else
				throw IndexOutOfBoundsException();
		}

		unsigned int	size() const{return (this->arrSize);}

		class IndexOutOfBoundsException : public std::exception
		{
			const char *what() const throw();
		};
};

template <typename T>
const char *Array<T>::IndexOutOfBoundsException::what() const throw()
{
	return ("Exception: Index is out of bounds");
}

#endif