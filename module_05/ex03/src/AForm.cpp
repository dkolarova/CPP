/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 17:07:21 by diana             #+#    #+#             */
/*   Updated: 2026/03/27 14:40:03 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"

AForm::AForm()
	: _name("Default name"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& src)
	: _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{}

AForm& AForm::operator=(const AForm& src)
{
	if (this != &src)
		this->_isSigned = src._isSigned;
	return *this;
}

AForm::~AForm() {}

// exceptions

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Form grade too high!:(";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Form grade too low!:(";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}

// members

std::string AForm::getName() const
{
	return _name;
}

bool AForm::isSigned() const
{
	return _isSigned;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

// Executions

void AForm::execute(Bureaucrat const & executor) const
{
	if (!this->_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > this->_gradeToExecute)
		throw GradeTooLowException();
	executeAction(); 
}

// writer

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os	<< "Form " << f.getName()
		<< ", Signed: " << (f.isSigned() ? "yes" : "no")
		<< ", grade to sign: " << f.getGradeToSign()
		<< ", grade to execute: " << f.getGradeToExecute();
	return os;
}