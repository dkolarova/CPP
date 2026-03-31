/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 16:41:51 by dkolarov          #+#    #+#             */
/*   Updated: 2026/03/31 16:44:52 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include <ctime>

int main() {
	// Seed random generator once at program start
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	// Generate a random object (A, B, or C)
	Base* obj = generate();

	// Identify using pointer version
	identify(obj);
	// Identify using reference version
	identify(*obj);

	delete obj;
	return 0;
}