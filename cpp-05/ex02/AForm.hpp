/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:07:17 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/09 12:52:37 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string 	name;
		bool				isSigned;
		const int			gradeToSign;
		const int			gradeToExec;
	public:
		AForm();
		AForm(const std::string _name, const int _gradeToSign, const int _gradeToExec);
		AForm(const AForm &src);
		AForm &operator=(const AForm &src);
		virtual ~AForm();

		virtual void				beSigned(Bureaucrat &man);
		virtual void				execute(Bureaucrat const & executor) const = 0;
		const std::string			getName() const;
		int							getGradeToSign() const;
		int							getGradeToExec() const;
		bool						getIsSigned() const;
		virtual const std::string	getTarget() const = 0;
		
		class GradeTooHighException : public std::exception
		{
			const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &output, const AForm &src);

#endif