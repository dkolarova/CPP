/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:40:39 by dkolarov          #+#    #+#             */
/*   Updated: 2026/03/30 13:37:54 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat marco("Marco", 20);
		Bureaucrat estefany("Estefany", 40);
		Form taxForm("Tax Form", 50, 30);

		marco.signForm(taxForm);
		estefany.signForm(taxForm);

		std::cout << taxForm << std::endl;
	}
	catch (const std::exception &e)
	{
	std::cout << "Exception caught: " << e.what() << std::endl;
	}
}