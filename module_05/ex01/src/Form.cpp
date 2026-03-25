/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 15:10:42 by dkolarov          #+#    #+#             */
/*   Updated: 2026/03/25 16:06:32 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"

Form::Form()
	: _name("Default Form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{}

Form::Form(const std::string& name, int _gradeToSign, int _gradeToExecute)
	: _name(name), _isSigned(false),
		_gradeToSign(_gradeToSign), _gradeToExecute(_gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& src)
	: _name(src._name), _isSigned(src._isSigned),
	_gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{}

Form& Form::operator=(const Form& src)
{
	if (this != &src)
		this->_isSigned = src._isSigned;
	return *this;
}

Form::~Form() {}

// exceptions

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form grade too high!:(";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form grade too low!:(";
}

// members

std::string Form::getName() const
{
	return _name;
}

bool Form::isSigned() const
{
	return _isSigned;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

// writer

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os	<< "Form " << f.getName()
		<< ", Signed: " << (f.isSigned() ? "yes" : "no")
		<< ", grade to sign: " << f.getGradeToSign()
		<< ", grade to execute: " << f.getGradeToExecute();
	return os;
}



