/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:01:56 by kalshaer          #+#    #+#             */
/*   Updated: 2023/12/21 21:06:57 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int		main(void)
{
	try
	{
		Intern someRandomIntern;
		AForm* rrf;
		(void)rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		delete rrf;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--------------------" << std::endl;

	try
	{
		Bureaucrat	b1("kalshaer", 5);
		Bureaucrat	b2("CEO", 1);


		Intern		slave;
		AForm		*form;
		
		form = slave.makeForm("shrubbery creation", "garden");
		if (!form)
		{
			std::cout << "Form is NULL" << std::endl;
			return (0);
		}
		b2.executeForm(*form);
		b1.signForm(*form);
		b2.executeForm(*form);
		delete form;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--------------------" << std::endl;

	try
	{
		Bureaucrat	b1("kalshaer", 1);
		Bureaucrat	b2("CEO", 1);


		Intern		slave;
		AForm		*form;
		
		form = slave.makeForm("presidential pardon", "garden");
		if (!form)
		{
			std::cout << "Form is NULL" << std::endl;
			return (0);
		}
		b2.executeForm(*form);
		b1.signForm(*form);
		b2.executeForm(*form);
		delete form;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--------------------" << std::endl;
	
	try
	{
		Bureaucrat	b1("kalshaer", -5);
		Bureaucrat	b2("CEO", 1);


		Intern		slave;
		AForm		*form = NULL;
		
		form = slave.makeForm("zzzzzzzz", "garden");
		if (!form)
		{
			std::cout << "Form is NULL" << std::endl;
			return (0);
		}
		b2.executeForm(*form);
		b1.signForm(*form);
		b2.executeForm(*form);
		delete form;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}