/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 16:31:36 by dkolarov          #+#    #+#             */
/*   Updated: 2026/03/31 17:09:20 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Base.hpp"

Base::~Base() {}

/*
	generate()
	Randomly instantiates A, B, or C.
*/
Base* generate(void) {
	int random = std::rand() % 3;

	switch (random) {
	case 0:
		std::cout << "Class A generated\n";
		return new A;
	case 1:
		std::cout << "Class B generated\n";
		return new B;
	case 2:
		std::cout << "Class C generated\n";
		return new C;
	default:
	// technically unreachable
		return 0;
	}
}

/*
	identify(Base* p)
	Identifies type via pointer casting.
	Returns NULL if cast fails.
*/
void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "Class A identified from pointer\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "Class B identified from pointer\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "Class C identified from pointer\n";
}

/*
	identify(Base& p)
	Identifies type via reference casting
	Throws exception if cast fails; catch exceptions to test all types
	// try casting to A, B, C
*/
void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);  
		std::cout << "Class A identified from reference\n";
		return;
	} catch (...) {}  // failed, continue

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "Class B identified from reference\n";
		return;
	} catch (...) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "Class C identified from reference\n";
	return;
	} catch (...) {}
}