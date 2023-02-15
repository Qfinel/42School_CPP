/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:07:05 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/09 13:03:53 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("Default"), gradeToSign(75), gradeToExec(75)
{
	this->isSigned = false;
}

AForm::AForm(const std::string _name, const int _gradeToSign, const int _gradeToExec) : name(_name),
gradeToSign(_gradeToSign), gradeToExec(_gradeToExec)
{
	if (this->gradeToSign > 150 || this->gradeToExec > 150)
		throw AForm::GradeTooLowException();
	if (this->gradeToSign < 1 || this->gradeToExec < 1)
		throw AForm::GradeTooHighException();
	this->isSigned = false;
}

AForm::AForm(const AForm &src) : name(src.name), gradeToSign(src.gradeToSign), gradeToExec(src.gradeToExec)
{
	*this = src;
}

AForm &AForm::operator=(const AForm &src)
{
	this->isSigned = src.isSigned;
	return (*this);
}

AForm::~AForm(){}

const std::string AForm::getName() const
{
	return (this->name);
}

int	AForm::getGradeToSign() const
{
	return (this->gradeToSign);
}

int	AForm::getGradeToExec() const
{
	return (this->gradeToExec);
}

bool AForm::getIsSigned() const
{
	return (this->isSigned);
}

void AForm::beSigned(Bureaucrat &man)
{
	if ((int)man.getGrade() <= this->gradeToSign)
		this->isSigned = true;
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Exception! Required grade is too low!");
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Exception! Required grade is too high!");
}

std::ostream &operator<<(std::ostream &ostream, const AForm &src)
{
	return (ostream << "Form name: " << src.getName() << ",\nGrade needed to sign: "
	<< src.getGradeToSign() << ",\nGrade needed to execute: "
	<< src.getGradeToExec() << ",\nThe Form is signed: " << src.getIsSigned());
}
