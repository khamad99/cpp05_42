/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:01:56 by kalshaer          #+#    #+#             */
/*   Updated: 2023/09/28 08:29:50 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int		main(void)
{
	try 
	{
		Bureaucrat kalshaer("Kalshaer", 137);
		ShrubberyCreationForm form = ShrubberyCreationForm("Home");
		std::cout << kalshaer << std::endl;
		std::cout << form << std::endl;
		kalshaer.signForm(form);
		std::cout << form << std::endl;
		kalshaer.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--------------------" << std::endl;
	
	try 
	{
		Bureaucrat kalshaer("Kalshaer", 5);
		PresidentialPardonForm form = PresidentialPardonForm("ppp");
		std::cout << kalshaer << std::endl;
		std::cout << form << std::endl;
		kalshaer.signForm(form);
		std::cout << form << std::endl;
		kalshaer.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--------------------" << std::endl;

	try 
	{
		Bureaucrat kalshaer("Kalshaer", 5);
		RobotomyRequestForm form = RobotomyRequestForm("rrr");
		std::cout << kalshaer << std::endl;
		std::cout << form << std::endl;
		kalshaer.signForm(form);
		std::cout << form << std::endl;
		kalshaer.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}