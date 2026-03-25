/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 15:08:37 by dkolarov          #+#    #+#             */
/*   Updated: 2026/03/25 17:30:14 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;

	public:
		Form();
		Form(const std::string& _name, int _gradeToSign, int _gradeToExecute);
		Form(const Form& src);
		Form& operator=(const Form& src);
		~Form();

	//exceptions
	class GradeTooHighException : public std::exception
	{
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		const char* what() const throw();
	};

	//getters
	std::string getName() const;
	bool isSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	//member func
	void beSigned(const Bureaucrat& b);
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif

/* Mental model

Bureaucrat = employee
Form = locked document

Employee tries to sign document
Document checks permission

If allowed → signed
If not → rejected (exception) */