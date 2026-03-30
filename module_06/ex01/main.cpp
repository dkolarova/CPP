/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:52:20 by dkolarov          #+#    #+#             */
/*   Updated: 2026/03/30 17:41:42 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main() {
	Data myData(420, "Test Object");

	// Serialize
	uintptr_t raw = Serializer::serialize(&myData);
	std::cout << "Serialized value: " << raw << std::endl;

	// Deserialize
	Data* ptr = Serializer::deserialize(raw);

	// Verify
	if (ptr == &myData)
	{
		std::cout << "Deserialization successful!" << std::endl;
		std::cout << "Data: id = " << ptr->id << ", name = " << ptr->name << std::endl;
	} 
	else
	{
		std::cout << "Deserialization failed!" << std::endl;
	}

	return 0;
}