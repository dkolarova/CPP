/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 16:01:30 by diana             #+#    #+#             */
/*   Updated: 2026/03/20 11:32:29 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	std::cout << "=== Creating FragTrap ===" << std::endl;
	FragTrap bot("FR4G");

	std::cout << "\n=== Testing Attack ===" << std::endl;
	bot.attack("enemy");

	std::cout << "\n=== Testing Take Damage ===" << std::endl;
	bot.takeDamage(20);
	bot.takeDamage(50);
	bot.takeDamage(40); // bring HP to 0

	std::cout << "\n=== Testing Repair ===" << std::endl;
	bot.beRepaired(30); // should still work if HP > 0, won't work if HP = 0

	std::cout << "\n=== Testing FragTrap Special Ability ===" << std::endl;
	bot.highFivesGuys();

	std::cout << "\n=== End of Scope ===" << std::endl;
	return 0;
}