/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 16:36:03 by diana             #+#    #+#             */
/*   Updated: 2026/03/14 09:59:05 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//contructor

/* 
ClapTrap constructor
        ↓
ScavTrap constructor
*/

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;

	std::cout << "ScavTrap " << _name << " created!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " has been destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0)
	{
		std::cout << _name << " is dead and can't attack." << std::endl;
		return ;
	}
	if (_energyPoints <= 0)
	{
		std::cout << _name << " has no energy to attack." << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ScavTrap " << _name << " viciosly attacks " << target << ", causing "
			  << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gate Keeper mode." << std::endl;
}

/* 
 ClapTrap
      /    |    \
 name  HP  energy
  |     |     |
 attack takeDamage repair
      |
      ↓
      ScavTrap
  HP=100 energy=50 damage=20
  attack() override
  guardGate()

So ScavTrap:

inherits behavior
modifies attack
adds new ability

*/