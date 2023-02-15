/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:37:59 by jtsizik           #+#    #+#             */
/*   Updated: 2023/02/14 13:04:19 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <iostream>
# include <stack>

template <class T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(){}
		MutantStack(const MutantStack &src) {*this = src;}
		MutantStack &operator=(const MutantStack &src) {this->c = src.c; return (*this);}
		~MutantStack(){}

		typedef typename std::stack<T>::container_type::iterator iterator; // 'stack' container is based on 'deque' container object called container_type in class definition (deque has iterators)
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		iterator begin() {return (this->c.begin());}
		iterator end() {return (this->c.end());}
		const_iterator begin() const {return (this->c.begin());}
		const_iterator end() const {return (this->c.end());}
};

#endif