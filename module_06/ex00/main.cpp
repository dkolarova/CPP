/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 19:32:00 by diana             #+#    #+#             */
/*   Updated: 2026/03/29 11:16:38 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char *argv[])
{
	if (argc == 2)
		ScalarConverter::convert(std::string(argv[1]));
	else
		std::cout << "Wrong number of arguments." << std::endl
		<< "Do: ./<compiled-file> <literal>" << std::endl;
	return 0;
}