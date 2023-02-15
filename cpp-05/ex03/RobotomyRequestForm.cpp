/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:00:44 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/09 15:25:47 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default"){}

RobotomyRequestForm::RobotomyRequestForm(const std::string _target) : AForm("RobotomyRequestForm", 72, 45), target(_target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
{
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this == &src)
		return (*this);
	return (*this);
}

const std::string RobotomyRequestForm::getTarget() const
{
	return (this->target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if ((int)executor.getGrade() <= this->getGradeToExec() && this->getIsSigned())
	{
		std::cout << "making drilling noises..." << std::endl;
		srand((unsigned)time(NULL));
		if (std::rand() % 2)
			std::cout << this->target << " has been robotomized successfully" << std::endl;
		else
			std::cout << "The robotomy failed." << std::endl;
	}
	else
		throw Bureaucrat::GradeTooLowException();
}
