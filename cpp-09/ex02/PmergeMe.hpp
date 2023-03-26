/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:46:31 by jtsizik           #+#    #+#             */
/*   Updated: 2023/03/25 15:58:23 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <vector>
# include <deque>

class PmergeMe
{
	private:
		std::vector<int> 	_vect;
		std::deque<int>		_deq;
		int					_k;

		bool isCorrectNum(std::string &str);
		void vectorMerge(int start, int mid, int end);
		void vectorInsert(int start, int end);
		void dequeMerge(int start, int mid, int end);
		void dequeInsert(int start, int end);
		void vectorSort(int start, int end);
		void dequeSort(int start, int end);
	public:
		PmergeMe();
		PmergeMe(std::vector<std::string> &arr);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void sort();
};

#endif