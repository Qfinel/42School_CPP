/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:07:05 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/09 12:54:12 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("Default"), gradeToSign(75), gradeToExec(75)
{
	this->isSigned = false;
}

Form::Form(const std::string _name, const int _gradeToSign, const int _gradeToExec) : name(_name),
gradeToSign(_gradeToSign), gradeToExec(_gradeToExec)
{
	if (this->gradeToSign > 150 || this->gradeToExec > 150)
		throw Form::GradeTooLowException();
	if (this->gradeToSign < 1 || this->gradeToExec < 1)
		throw Form::GradeTooHighException();
	this->isSigned = false;
}

Form::Form(const Form &src) : name(src.name), gradeToSign(src.gradeToSign), gradeToExec(src.gradeToExec)
{
	*this = src;
}

Form &Form::operator=(const Form &src)
{
	this->isSigned = src.isSigned;
	return (*this);
}

Form::~Form(){}

const std::string Form::getName() const
{
	return (this->name);
}

int	Form::getGradeToSign() const
{
	return (this->gradeToSign);
}

int	Form::getGradeToExec() const
{
	return (this->gradeToExec);
}

bool Form::getIsSigned() const
{
	return (this->isSigned);
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Exception! Required grade is too low!");
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Exception! Required grade is too high!");
}

void Form::beSigned(Bureaucrat &man)
{
	if ((int)man.getGrade() <= this->gradeToSign)
		this->isSigned = true;
}

std::ostream &operator<<(std::ostream &ostream, const Form &src)
{
	return (ostream << "Form name: " << src.getName() << ",\nGrade needed to sign: "
	<< src.getGradeToSign() << ",\nGrade needed to execute: "
	<< src.getGradeToExec() << ",\nThe form is signed: " << src.getIsSigned());
}
