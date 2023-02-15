/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:01:55 by jtsizik           #+#    #+#             */
/*   Updated: 2023/02/14 19:38:48 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>
# include <vector>
# include <iterator>

template <typename T>
bool	easyfind(T obj, int i)
{
	if (std::find(obj.begin(), obj.end(), i) == obj.end())
		return (false);
	return (true);
}

#endif