/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 16:01:30 by diana             #+#    #+#             */
/*   Updated: 2026/03/13 16:15:58 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    ClapTrap bot("CL4P-TP");

    // Test attack
    bot.attack("Dummy Target");

    // Test taking damage
    bot.takeDamage(3);

    // Test repairing
    bot.beRepaired(5);

    // Test behavior when dead
    bot.takeDamage(15);
    bot.attack("Another Dummy"); // Should print: cannot attack
    bot.beRepaired(5);          // Should print: cannot repair

    // Test energy depletion
    ClapTrap bot2("ENERGY");
    for (int i = 0; i < 11; ++i)
        bot2.attack("Target");  // Last attack should fail due to 0 energy

    return 0;
}