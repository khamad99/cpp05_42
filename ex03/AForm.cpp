/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:37:19 by kalshaer          #+#    #+#             */
/*   Updated: 2023/09/28 11:11:46 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	return ;
}

AForm::AForm(std::string name, size_t gradeToSign, size_t gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	return ;
}

AForm::AForm(AForm const &src) : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
	return ;
}

AForm::~AForm()
{
	return ;
}

AForm &AForm::operator=(AForm const &src)
{
	if (this != &src)
		this->_signed = src._signed;
	return (*this);
}

std::string const	&AForm::getName() const
{
	return (this->_name);
}

bool				AForm::getSigned() const
{
	return (this->_signed);
}

size_t				AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

size_t				AForm::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

void				AForm::beSigned(Bureaucrat const &src)
{
	if (src.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form not signed");
}

std::ostream &operator<<(std::ostream &o, AForm const &src)
{
	o << src.getName() << " form, grade to sign: " << src.getGradeToSign() << ", grade to execute: " << src.getGradeToExecute() << ", signed: " << src.getSigned();
	return (o);
}

void				AForm::execute(Bureaucrat const &executor) const
{
	if (!this->_signed)
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->_gradeToExecute)
		throw AForm::GradeTooLowException();
	else
		this->executeAction();
}