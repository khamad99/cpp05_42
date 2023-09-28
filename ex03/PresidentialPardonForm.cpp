/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:55:42 by kalshaer          #+#    #+#             */
/*   Updated: 2023/09/28 07:47:54 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("default", 25, 5), _target("default")
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src)
{
	*this = src;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	return ;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
	if (this != &src)
		AForm::operator=(src);
	return (*this);
}

std::string const	&PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void				PresidentialPardonForm::executeAction() const
{
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
	return ;
}

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &src)
{
	o << "Form " << src.getName() << " is ";
	if (src.getSigned() == false)
		o << "not ";
	o << "signed, grade to sign is " << src.getGradeToSign() << ", grade to execute is " << src.getGradeToExecute() << "." << std::endl;
	return (o);
}