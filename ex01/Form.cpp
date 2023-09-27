/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:37:19 by kalshaer          #+#    #+#             */
/*   Updated: 2023/09/27 11:54:44 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	return ;
}

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	return ;
}

Form::Form(Form const &src) : _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
	*this = src;
	return ;
}

Form::~Form()
{
	return ;
}

Form &Form::operator=(Form const &src)
{
	if (this != &src)
		this->_signed = src._signed;
	return (*this);
}

std::string const	&Form::getName() const
{
	return (this->_name);
}

bool				Form::getSigned() const
{
	return (this->_signed);
}

int					Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int					Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

void				Form::beSigned(Bureaucrat const &src)
{
	if (src.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	else
		this->_signed = true;
	return ;
}

const char			*Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}


const char			*Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

std::ostream &operator<<(std::ostream &o, Form const &src)
{
	o << "Form " << src.getName() << " is ";
	if (src.getSigned())
		o << "signed";
	else
		o << "not signed";
	o << " and require grade " << src.getGradeToSign() << " to be signed and grade " << src.getGradeToExecute() << " to be executed";
	return (o);
}

