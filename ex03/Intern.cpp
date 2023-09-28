/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 09:16:15 by kalshaer          #+#    #+#             */
/*   Updated: 2023/09/28 10:54:18 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const & src)
{
	*this = src;
}

Intern::~Intern()
{
}

Intern & Intern::operator=(Intern const & rhs)
{
	(void)rhs;
	return (*this);
}

struct FormType
{
	std::string name;
	AForm *(Intern::*func)(std::string target);
};

AForm * Intern::makeForm(std::string name, std::string target)
{
	FormType forms[] = {
		{"presidential pardon", &Intern::makePresidentialPardonForm},
		{"robotomy request", &Intern::makeRobotomyRequestForm},
		{"shrubbery creation", &Intern::makeShrubberyCreationForm}
	};

	for (int i = 0; i < 3; i++)
	{
		if (name == forms[i].name)
		{
			std::cout << "Intern creates " << name << " form" << std::endl;
			return ((this->*forms[i].func)(target));
		}
	}

	std::cout << "Intern can't create " << name << " form" << std::endl;
	return (NULL);
}

AForm * Intern::makePresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm * Intern::makeRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm * Intern::makeShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}
