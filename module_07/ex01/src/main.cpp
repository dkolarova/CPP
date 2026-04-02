/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 13:46:51 by dkolarov          #+#    #+#             */
/*   Updated: 2026/04/01 16:38:01 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

// Function to print an element (non-const)
template <typename T>
void print(T &x)
{
	std::cout << x << std::endl;
}

// Function to increment an element (non-const)
void increment(int &x)
{
	x += 1;
}

// Function to print element (const)
void printConst(const int &x)
{
	std::cout << x << std::endl;
}

int main()
{
	int arr[5] = {1, 2, 3, 4, 5};
	iter(arr, 5, print<int>);
	std::cout << std::endl;

	iter(arr, 5, increment);
	iter(arr, 5, print<int>);
	std::cout << std::endl;

	const int cArr[3] = {10, 20, 30};
	iter(cArr, 3, printConst);
	std::cout << std::endl;

	std::string strArr[3] = {"apple", "banana", "cherry"};
	iter(strArr, 3, print<std::string>);
	std::cout << std::endl;

	return 0;
}

//iter is just a reusable loop that applies a function to every element of an array.