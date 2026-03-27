/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 17:05:16 by diana             #+#    #+#             */
/*   Updated: 2026/03/27 14:35:56 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(NULL));

	std::cout << "===== TEST 1: Shrubbery =====" << std::endl;
	{
		Bureaucrat bob("Bob", 1);
		ShrubberyCreationForm form("home");

		bob.executeForm(form); // ❌ not signed
		bob.signForm(form);    // ✅ sign
		bob.executeForm(form); // ✅ create file
	}

	std::cout << "\n===== TEST 2: Robotomy =====" << std::endl;
	{
		Bureaucrat alice("Alice", 1);
		RobotomyRequestForm form("Bender");

		alice.signForm(form);

		for (int i = 0; i < 5; i++)
			alice.executeForm(form); // random success/fail
	}

	std::cout << "\n===== TEST 3: Presidential =====" << std::endl;
	{
		Bureaucrat boss("Boss", 1);
		PresidentialPardonForm form("Arthur Dent");

		boss.signForm(form);
		boss.executeForm(form);
	}

	std::cout << "\n===== TEST 4: Grade too low =====" << std::endl;
	{
		Bureaucrat low("LowGuy", 150);
		PresidentialPardonForm form("Ford Prefect");

		low.signForm(form);    // ❌ should fail
		low.executeForm(form); // ❌ should fail
	}

	std::cout << "\n===== TEST 5: Borderline grades =====" << std::endl;
	{
		Bureaucrat mid("Mid", 137);
		ShrubberyCreationForm form("garden");

		mid.signForm(form);    // ✅ (145 required)
		mid.executeForm(form); // ✅ (137 required)
	}

	return 0;
}
