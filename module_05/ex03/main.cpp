/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 17:05:16 by diana             #+#    #+#             */
/*   Updated: 2026/03/28 17:42:56 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Intern intern;

	// Valid forms
	AForm* rrf = intern.makeForm("robotomy request", "Bender");
	if (rrf) delete rrf;

	AForm* scf = intern.makeForm("shrubbery creation", "Home");
	if (scf) delete scf;

	AForm* ppf = intern.makeForm("presidential pardon", "Marvin");
	if (ppf) delete ppf;

	// Invalid form
	AForm* unknown = intern.makeForm("unknown form", "Target");
	if (unknown) delete unknown;

	return 0;
}