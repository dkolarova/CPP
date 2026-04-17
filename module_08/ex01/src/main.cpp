/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 10:59:56 by dkolarov          #+#    #+#             */
/*   Updated: 2026/04/17 13:08:12 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	std::cout << "=== BASIC TEST ===" << std::endl;
	try
	{
		Span sp(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== OVERFLOW TEST ===" << std::endl;
	try
	{
		Span sp(2);

		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3); // should throw
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== NOT ENOUGH ELEMENTS TEST ===" << std::endl;
	try
	{
		Span sp(5);

		sp.addNumber(42);
		std::cout << sp.shortestSpan() << std::endl; // should throw
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== LARGE TEST (10,000 numbers) ===" << std::endl;
	try
	{
		Span sp(10000);

		for (int i = 0; i < 10000; i++)
			sp.addNumber(rand());

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== RANGE TEST ===" << std::endl;
	try
	{
		Span sp(5);

		std::vector<int> numbers;
		numbers.push_back(5);
		numbers.push_back(10);
		numbers.push_back(15);
		numbers.push_back(20);
		numbers.push_back(35);

		sp.addRange(numbers.begin(), numbers.end());

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== ZERO CAPACITY ===" << std::endl;
	try
	{
		Span sp(0);

		sp.addNumber(42);
	}
	catch(const std::exception& e)
	{
		std::cout << "[Zero capacity] Exception: " << e.what() << std::endl;
	}
	
	
	srand(time(NULL));
	return 0;
}
