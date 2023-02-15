/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:08:39 by jtsizik           #+#    #+#             */
/*   Updated: 2022/12/09 15:02:35 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default"){}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string _target) : AForm("ShrubberyCreationForm", 145, 137), target(_target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
{
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this == &src)
		return (*this);
	return (*this);
}

const std::string ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if ((int)executor.getGrade() <= this->getGradeToExec() && this->getIsSigned())
	{
		std::ofstream	outfile;
		std::string		fileName;

		fileName.append(target + "_shrubbery");
		outfile.open(fileName);
		if (outfile.is_open())
		{
			outfile <<
			"                                     .         ;" << std::endl
			<< "        .              .              ;%     ;;" << std::endl
			<< "          ,           ,                :;%  %;" << std::endl
			<< "           :         ;                   :;%;'     .," << std::endl
			<< "  ,.        %;     %;            ;        %;'    ,;" << std::endl
			<< "    ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl
			<< "     %;       %;%;      ,  ;       %;  ;%;   ,%;'" << std::endl
			<< "      ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl
			<< "       `%;.     ;%;     %;'         `;%%;.%;'" << std::endl
			<< "        `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl
			<< "           `:%;.  :;bd%;          %;@%;'" << std::endl
			<< "             `@%:.  :;%.         ;@@%;'" << std::endl
			<< "               `@%.  `;@%.      ;@@%;" << std::endl
			<< "                 `@%%. `@%%    ;@@%;" << std::endl
			<< "                   ;@%. :@%%  %@@%;" << std::endl
			<< "                     %@bd%%%bd%%:;" << std::endl
			<< "                       #@%%%%%:;;" << std::endl
			<< "                       %@@%%%::;" << std::endl
			<< "                       %@@@%(o);  . '" << std::endl
			<< "                       %@@@o%;:(.,'" << std::endl
			<< "                   `.. %@@@o%::;" << std::endl
			<< "                      `)@@@o%::;" << std::endl
			<< "                       %@@(o)::;" << std::endl
			<< "                      .%@@@@%::;" << std::endl
			<< "                      ;%@@@@%::;." << std::endl
			<< "                     ;%@@@@%%:;;;." << std::endl
			<< "                 ...;%@@@@@%%:;;;;,.." << std::endl;
			outfile.close();
		}
		else
			throw std::exception();
	}
	else
		throw Bureaucrat::GradeTooLowException();
}