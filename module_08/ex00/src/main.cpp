/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 15:58:54 by diana             #+#    #+#             */
/*   Updated: 2026/04/17 12:04:16 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Easyfind.hpp"

int main()
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(78);

	try
	{
		std::vector<int>::iterator it1 = easyfind(vec, 1);
		std::cout << "Found in vector: " << *it1 << std::endl;

		std::list<int>::iterator it2 = easyfind(lst, 78);
		std::cout << "Found in list: " << *it2 << std::endl;

		std::list<int>::iterator it3 = easyfind(lst, 90);
		std::cout << "Found in list: " << *it3 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	return 0;	
}