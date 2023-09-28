/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:29:54 by kalshaer          #+#    #+#             */
/*   Updated: 2023/09/28 11:11:40 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		bool				_signed;
		size_t const			_gradeToSign;
		size_t const			_gradeToExecute;
		
	public:
		AForm();
		AForm(std::string name, size_t gradeToSign, size_t gradeToExecute);
		AForm(AForm const &src);
		virtual ~AForm();
		AForm &operator=(AForm const &src);
		std::string const	&getName() const;
		bool				getSigned() const;
		size_t				getGradeToSign() const;
		size_t				getGradeToExecute() const;
		void				beSigned(Bureaucrat const &src);
		virtual void 		execute(Bureaucrat const &executor) const;
		virtual void		executeAction() const = 0;
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, AForm const &src);


#endif