/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:40:39 by dkolarov          #+#    #+#             */
/*   Updated: 2026/03/25 15:07:33 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat a("Antonia", 2);
		std::cout << a << std::endl;

		a.incrementGrade(); // work
		std::cout << a << std::endl;

		a.incrementGrade(); // throw
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << std::endl;
	
	try
	{
		Bureaucrat b("Jose", 0);
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}