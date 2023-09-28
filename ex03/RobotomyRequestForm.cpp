/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:13:56 by kalshaer          #+#    #+#             */
/*   Updated: 2023/09/28 08:02:27 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("default", 72, 45), _target("default")
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src)
{
	*this = src;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return ;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
	if (this != &src)
		AForm::operator=(src);
	return (*this);
}

std::string const	&RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void				RobotomyRequestForm::executeAction() const
{
	std::cout << "Drrrrrrr...... Bzzzzzzz..... Drrrrrrr!" << std::endl;
	std::srand(static_cast<unsigned>(std::time(0)));
	if (rand() % 2 == 1)
		std::cout << _target << " has been robotized" << std::endl;
	else
		std::cout << "Robotization failed" << std::endl;
}

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const &src)
{
	o << "Form " << src.getName() << " is ";
	if (src.getSigned() == false)
		o << "not ";
	o << "signed, grade to sign is " << src.getGradeToSign() << ", grade to execute is " << src.getGradeToExecute() << "." << std::endl;
	return (o);
}