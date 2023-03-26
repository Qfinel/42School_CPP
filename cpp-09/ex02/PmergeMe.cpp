/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:46:17 by jtsizik           #+#    #+#             */
/*   Updated: 2023/03/25 17:30:16 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {_k = 10;}

PmergeMe::PmergeMe(std::vector<std::string> &arr)
{
	for (std::vector<std::string>::iterator it = arr.begin(); it != arr.end(); it++)
	{
		if (isCorrectNum(*it))
		{
			this->_vect.push_back(std::atoi((*it).c_str()));
			this->_deq.push_back(std::atoi((*it).c_str()));
		}
		else
			throw std::runtime_error("Error");
	}
	_k = 10;
}

PmergeMe::PmergeMe(const PmergeMe &other) {*this = other;}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	this->_vect = other._vect;
	this->_deq = other._deq;
	this->_k = other._k;
	return (*this);
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::isCorrectNum(std::string &str)
{
	for (std::string::iterator it = str.begin(); it != str.end(); it++)
	{
		if (!std::isdigit(*it))
			return (false);
	}
	return (true);
}

void PmergeMe::vectorMerge(int start, int mid, int end)
{
	int left_size = mid - start + 1;
	int right_size = end - mid;
	std::vector<int>	left(left_size);
	std::vector<int>	right(right_size);
	for (int i = 0; i < left_size; i++)
		left[i] = _vect[start + i];
	for (int i = 0; i < right_size; i++)
		right[i] = _vect[mid + 1 + i];

	int left_i = 0;
	int	right_i = 0;

	for (int i = start; i <= end; i++)
	{
		if (right_i == right_size) {
			_vect[i] = left[left_i];
			left_i++;
		} else if (left_i == left_size) {
			_vect[i] = right[right_i];
			right_i++;
		} else if (right[right_i] > left[left_i]) {
            _vect[i] = left[left_i];
            left_i++;
        } else {
            _vect[i] = right[right_i];
            right_i++;
        }
	}
}

void PmergeMe::vectorInsert(int start, int end)
{
	for (int i = start; i < end; i++)
	{
		int tmp = _vect[i + 1];
		int j = i + 1;
		while (j > start && tmp < _vect[j - 1])
		{
			_vect[j] = _vect[j - 1];
			j--;
		}
		_vect[j] = tmp;
	}
}

void PmergeMe::dequeMerge(int start, int mid, int end)
{
	int left_size = mid - start + 1;
	int right_size = end - mid;
	std::deque<int>	left(left_size);
	std::deque<int>	right(right_size);
	for (int i = 0; i < left_size; i++)
		left[i] = _deq[start + i];
	for (int i = 0; i < right_size; i++)
		right[i] = _deq[mid + 1 + i];

	int left_i = 0;
	int	right_i = 0;

	for (int i = start; i <= end; i++)
	{
		if (right_i == right_size) {
			_deq[i] = left[left_i];
			left_i++;
		} else if (left_i == left_size) {
			_deq[i] = right[right_i];
			right_i++;
		} else if (right[right_i] > left[left_i]) {
            _deq[i] = left[left_i];
            left_i++;
        } else {
            _deq[i] = right[right_i];
            right_i++;
        }
	}
}

void PmergeMe::dequeInsert(int start, int end)
{
	for (int i = start; i < end; i++)
	{
		int tmp = _deq[i + 1];
		int j = i + 1;
		while (j > start && tmp < _deq[j - 1])
		{
			_deq[j] = _deq[j - 1];
			j--;
		}
		_deq[j] = tmp;
	}
}

void PmergeMe::vectorSort(int start, int end)
{
	if (end - start + 1 <= _k)
		vectorInsert(start, end);
	else
	{
		int mid = (start + end) / 2;
		vectorSort(start, mid);
		vectorSort(mid + 1, end);
		vectorMerge(start, mid, end);
	}
}

void PmergeMe::dequeSort(int start, int end)
{
	if (end - start + 1 <= _k)
		dequeInsert(start, end);
	else
	{
		int mid = (start + end) / 2;
		dequeSort(start, mid);
		dequeSort(mid + 1, end);
		dequeMerge(start, mid, end);
	}
}

void PmergeMe::sort()
{
	std::cout << "BEFORE: ";
	for (std::vector<int>::iterator it = _vect.begin(); it != _vect.end(); it++)
		std::cout << " " << *it;
	std::cout << std::endl;

	std::clock_t start_vect = clock();
	vectorSort(0, _vect.size() - 1);
	std::clock_t end_vect = clock();

	std::clock_t start_deq = clock();
	dequeSort(0, _deq.size() - 1);
	std::clock_t end_deq = clock();

	std::cout << "AFTER:  ";
	for (std::vector<int>::iterator it = _vect.begin(); it != _vect.end(); it++)
		std::cout << " " << *it;
	std::cout << std::endl;

	double time_vect = double(end_vect - start_vect) / CLOCKS_PER_SEC * 10000000; // Convert to microseconds
	double time_deq = double(end_deq - start_deq) / CLOCKS_PER_SEC * 10000000;
	std::cout << "Time to process a range of " << _vect.size() << " elements with std::vector : " << time_vect << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque : " << time_deq << " us" << std::endl;
}