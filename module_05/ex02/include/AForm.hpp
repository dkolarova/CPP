/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 17:05:44 by diana             #+#    #+#             */
/*   Updated: 2026/03/27 14:37:33 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <Bureaucrat.hpp>
#include <iostream>

class AForm
{
	private:
		const	std::string _name;
		bool	_isSigned;
		const	int _gradeToSign;
		const	int _gradeToExecute;

	public:
		AForm();
		AForm(const AForm& src);
		AForm(const std::string& name, int gradeToSign, int gradeToExecute);
		AForm& operator=(const AForm& src);
		virtual ~AForm();

	//exceptions

	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw();
	};

	class FormNotSignedException: public std::exception
	{
		public:
			const char* what() const throw();
	};

	//getters
	std::string getName() const;
	bool isSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	//core logic
	void beSigned(const Bureaucrat& b);
	
	//new execution system
	void execute(Bureaucrat const & executor) const;

	protected:
		virtual void executeAction() const = 0; // we have to make class abstract
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif