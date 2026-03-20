/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 16:01:30 by diana             #+#    #+#             */
/*   Updated: 2026/03/20 11:54:36 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
	std::cout << "=== ClapTrap Test ===\n";
	ClapTrap clap("CL4P-TP");
	clap.attack("Dummy Target");
	clap.takeDamage(15);
	clap.beRepaired(10);

	std::cout << "\n=== ScavTrap Test ===\n";
	ScavTrap scav("SC4V-TP");

	scav.attack("Training Dummy");
	scav.takeDamage(30);
	scav.beRepaired(20);
	scav.guardGate();

	std::cout << "\n=== Energy Depletion Test ===\n";
	for (int i = 0; i < 51; ++i)
		scav.attack("Target");	// Last attack should fail due to 0 energy

	return 0;
}