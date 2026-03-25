/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:40:39 by dkolarov          #+#    #+#             */
/*   Updated: 2026/03/25 17:26:52 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

int main()
{
	Bureaucrat marco("Marco", 50);
	Bureaucrat estefany("Estefany", 40);
	Form taxForm("Tax Form", 50, 30);

	marco.signForm(taxForm);
	estefany.signForm(taxForm);

	std::cout << taxForm << std::endl;
}