/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:13:34 by jtsizik           #+#    #+#             */
/*   Updated: 2023/02/11 15:00:52 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()	{}

Serializer::Serializer(const Serializer &src)	{*this = src;}

Serializer &Serializer::operator=(const Serializer &src)	{(void)src; return (*this);}

Serializer::~Serializer()	{}

Serializer	&Serializer::getSerializer()
{
	static Serializer	instance;
	return (instance);
}

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t newPtr = reinterpret_cast<uintptr_t>(ptr);
	return newPtr;
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data *ptr = reinterpret_cast<Data *>(raw);
	return ptr;
}