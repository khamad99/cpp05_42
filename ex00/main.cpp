/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:01:56 by kalshaer          #+#    #+#             */
/*   Updated: 2023/09/27 10:47:16 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int		main(void)
{
	try 
	{
		Bureaucrat kalshaer("Kalshaer", 155);
		std::cout << kalshaer << std::endl;
		kalshaer.decrementGrade();
		std::cout << kalshaer << std::endl;
		kalshaer.decrementGrade();
		std::cout << kalshaer << std::endl;
		kalshaer.decrementGrade();
		std::cout << kalshaer << std::endl;

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--------------------" << std::endl;
	
	try
	{
		Bureaucrat kalshaer("Kalshaer", 148);
		std::cout << kalshaer << std::endl;
		kalshaer.decrementGrade();
		std::cout << kalshaer << std::endl;
		kalshaer.decrementGrade();
		std::cout << kalshaer << std::endl;
		kalshaer.decrementGrade();
		std::cout << kalshaer << std::endl;

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--------------------" << std::endl;
	
	try
	{
		Bureaucrat tmp;
		Bureaucrat kalshaer(tmp);
		std::cout << kalshaer << std::endl;
		kalshaer.incrementGrade();
		std::cout << kalshaer << std::endl;
		kalshaer.incrementGrade();
		std::cout << kalshaer << std::endl;
		kalshaer.incrementGrade();
		std::cout << kalshaer << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}