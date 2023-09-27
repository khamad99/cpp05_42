/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:01:56 by kalshaer          #+#    #+#             */
/*   Updated: 2023/09/27 11:59:25 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int		main(void)
{
	try 
	{
		Bureaucrat kalshaer("Kalshaer", 150);
		Form form("Form", 149, 150);
		std::cout << kalshaer << std::endl;
		std::cout << form << std::endl;
		kalshaer.signForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--------------------" << std::endl;
	
	try 
	{
		Bureaucrat kalshaer("Kalshaer", 1);
		Form form("Form", 149, 150);
		std::cout << kalshaer << std::endl;
		std::cout << form << std::endl;
		kalshaer.signForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--------------------" << std::endl;

	try 
	{
		Bureaucrat kalshaer("Kalshaer", 5);
		Form form("Form", 5, 150);
		std::cout << kalshaer << std::endl;
		std::cout << form << std::endl;
		kalshaer.signForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}