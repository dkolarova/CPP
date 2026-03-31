/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:52:20 by dkolarov          #+#    #+#             */
/*   Updated: 2026/03/31 13:53:24 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main()
{
	// Create and initialize Data
	Data original;
	original.id = 42;
	original.name = "Test Object";

	// Print original values
	std::cout << "Original Data:" << std::endl;
	std::cout << "Address: " << &original << std::endl;
	std::cout << "ID: " << original.id << std::endl;
	std::cout << "Name: " << original.name << std::endl;

	// Serialize
	uintptr_t raw = Serializer::serialize(&original);
	std::cout << "\nSerialized value: " << raw << std::endl;

	// Deserialize
	Data* deserialized = Serializer::deserialize(raw);

	// Print deserialized values
	std::cout << "\nDeserialized Data:" << std::endl;
	std::cout << "Address: " << deserialized << std::endl;
	std::cout << "ID: " << deserialized->id << std::endl;
	std::cout << "Name: " << deserialized->name << std::endl;

	// Check if pointers match
	if (deserialized == &original)
		std::cout << "\nSuccess: Pointers match!" << std::endl;
	else
		std::cout << "\nError: Pointers do NOT match!" << std::endl;

	return 0;
}