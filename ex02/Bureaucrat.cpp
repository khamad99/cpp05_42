/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 08:53:06 by kalshaer          #+#    #+#             */
/*   Updated: 2023/09/27 13:26:16 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	return ;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name)
{
	*this = src;
	return ;
}

Bureaucrat::~Bureaucrat()
{
	return ;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src)
{
	if (this != &src)
		this->_grade = src._grade;
	return (*this);
}

std::string const	&Bureaucrat::getName() const
{
	return (this->_name);
}

int					Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void				Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
	return ;
}

void				Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
	return ;
}

const char			*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char			*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &src)
{
	o << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
	return (o);
}

void			Bureaucrat::signForm(Form &src)
{
	if (src.getSigned())
		std::cout << this->_name << " cannot sign " << src.getName() << " because it's already signed" << std::endl;
	else if (this->_grade > src.getGradeToSign())
		std::cout << this->_name << " cannot sign " << src.getName() << " because bureaucrat grade is too low" << std::endl;
	else
	{
		std::cout << this->_name << " signs " << src.getName() << std::endl;
		src.beSigned(*this);
	}
	return ;
}

void			Bureaucrat::executeForm(Form const &src)
{
	if (src.getSigned() == false)
		std::cout << this->_name << " cannot execute " << src.getName() << " because it's not signed" << std::endl;
	else if (this->_grade > src.getGradeToExecute())
		std::cout << this->_name << " cannot execute " << src.getName() << " because bureaucrat grade is too low" << std::endl;
	else
	{
		std::cout << this->_name << " executes " << src.getName() << std::endl;
		src.execute(*this);
	}
	return ;
}

