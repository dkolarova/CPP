/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:40:59 by dkolarov          #+#    #+#             */
/*   Updated: 2026/03/25 12:46:54 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BUREAUCRAT_HPP
#define	BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat 
{
	private:
		const std::string _name;
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string _name, int _grade);
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat& operator=(const Bureaucrat& src);
		~Bureaucrat();

	//getters
	std::string getName() const;
	int getGrade() const;

	//grade control
	void incrementGrade();
	void decrementGrade();

	//exceptions
	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw(); //“A function that returns a read-only string, does not modify the object, and does not throw exceptions”
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw();
	};
};

//operator<< does not store anything or change the object. It just defines how to convert your object into text for output.
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

//how it works ->
/* std::ostream& os → the stream you are printing to (usually std::cout)
const Bureaucrat& b → the object you want to print
std::ostream& → return the stream so you can chain << calls

b.getName() → gets the name
b.getGrade() → gets the grade
os << ... → writes text to the stream
return os; → allows chaining like std::cout << b << "\n"; */

#endif
