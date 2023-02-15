/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:06:07 by jtsizik           #+#    #+#             */
/*   Updated: 2022/11/30 15:10:09 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include <sstream>

class PhoneBook
{
	private:
		int		index;
		int		total;
		Contact	contacts[8];
	public:
		PhoneBook();
		~PhoneBook();

		void	addContact();
		void	showContacts();
};

#endif