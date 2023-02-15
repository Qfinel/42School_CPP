/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:36:33 by jtsizik           #+#    #+#             */
/*   Updated: 2023/02/14 13:04:51 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <vector>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	MutantStack<int>::const_iterator it1 = mstack.begin();
	MutantStack<int>::const_iterator ite1 = mstack.end();
	++it1;
	--it1;
	while (it1 != ite1)
	{
		std::cout << *it1 << std::endl;
		++it1;
	}
	std::stack<int> s(mstack);
	return 0;
}

// int main()
// {
// 	std::vector<int> mstack;
// 	mstack.push_back(5);
// 	mstack.push_back(17);
// 	std::cout << *(mstack.end() - 1) << std::endl;
// 	mstack.erase(mstack.end() - 1);
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push_back(3);
// 	mstack.push_back(5);
// 	mstack.push_back(737);
// 	mstack.push_back(0);
// 	std::vector<int>::iterator it = mstack.begin();
// 	std::vector<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	std::vector<int>::const_iterator it1 = mstack.begin();
// 	std::vector<int>::const_iterator ite1 = mstack.end();
// 	++it1;
// 	--it1;
// 	while (it1 != ite1)
// 	{
// 		std::cout << *it1 << std::endl;
// 		++it1;
// 	}
// 	return 0;
// } // SAME OUTPUT