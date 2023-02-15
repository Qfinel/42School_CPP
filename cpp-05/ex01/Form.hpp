/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:07:17 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/09 12:52:37 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string 	name;
		bool				isSigned;
		const int			gradeToSign;
		const int			gradeToExec;
	public:
		Form();
		Form(const std::string _name, const int _gradeToSign, const int _gradeToExec);
		Form(const Form &src);
		Form &operator=(const Form &src);
		~Form();

		void				beSigned(Bureaucrat &man);
		const std::string	getName() const;
		int					getGradeToSign() const;
		int					getGradeToExec() const;
		bool				getIsSigned() const;
		
		class GradeTooHighException : public std::exception
		{
			const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &output, const Form &src);

#endif