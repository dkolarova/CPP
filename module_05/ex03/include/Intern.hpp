/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 16:25:12 by diana             #+#    #+#             */
/*   Updated: 2026/03/30 13:59:54 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		// Typedef for a pointer to a function that takes a string and returns AForm*
		typedef	AForm* (*FormCreator)(const std::string& target);
		
		// Static functions wrap constructors to be used in function pointer array
		static	AForm* _createShrubbery(const std::string& target);
		static	AForm* _createRobotomy(const std::string& target);
		static	AForm* _createPresidential(const std::string& target);
		
	public:
		// Canonical form
		Intern();
		Intern(const Intern& src);
		Intern& operator=(const Intern& src);
		~Intern();

		// Main factory function: returns a dynamically allocated form based on name
		AForm* makeForm(const std::string& name, const std::string& target);
};

#endif