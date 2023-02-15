/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:13:07 by jtsizik           #+#    #+#             */
/*   Updated: 2023/02/11 14:59:03 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include "Data.hpp"

class  Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &src);
		Serializer &operator=(const Serializer &src);
		~Serializer();

	public:
		static		Serializer	&getSerializer();
		uintptr_t 	serialize(Data* ptr);
		Data* 		deserialize(uintptr_t raw);

		class WrongTypeException : public std::exception
		{
			const char *what() const throw();
		};
};


#endif