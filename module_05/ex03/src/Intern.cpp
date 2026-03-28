/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inter.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 17:37:25 by diana             #+#    #+#             */
/*   Updated: 2026/03/28 17:42:17 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

//nothing to copy
Intern::Intern(const Intern& src)
{
	(void)src;
}

//assigment
Intern& Intern::operator=(const Intern& src)
{
	(void)src;
	return *this;
}

Intern::~Intern(){}

// static creation funcs -> these wrap concrete form constructors and return a pointer to AForm:)

AForm* Intern::_createShrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::_createRobotomy(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::_createPresidential(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

//makeForm

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
	// Array of valid form names
	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	// Array of corresponding function pointers
	FormCreator creators[3] = {
		&_createShrubbery,
		&_createRobotomy,
		&_createPresidential
	};

	// Loop to find the correct form
	for (int i = 0; i < 3; i++)
	{
		if (name == formNames[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return creators[i](target); // Call the creation function
		}
	}

	// Form name not found
	std::cerr << "Intern couldn't find form: " << name << std::endl;
	return NULL;
}
