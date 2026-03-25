/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:40:53 by dkolarov          #+#    #+#             */
/*   Updated: 2026/03/25 16:20:57 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

Bureaucrat::Bureaucrat(): _name("sin nombre:("), _grade(150){}

Bureaucrat::Bureaucrat(const std::string _name, int _grade) : _name(_name)
{
	if (_grade < 1)
		throw GradeTooLowException();
	if (_grade > 150)
		throw GradeTooHighException();
	this->_grade = _grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
{
	this->_grade = src._grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
	if (this != &src)
		this->_grade = src._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{}

// getters

std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

// grade controls

void Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

// forms

void Bureaucrat::signForm(Form& f) const
{
	try
	{
		f.beSigned(*this);
		std::cout << _name << " signed " << f.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
	}
	
}

// exceptions

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high!:(";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low!:(";
}

// operator "writer"

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}