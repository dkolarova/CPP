/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:45:30 by diana             #+#    #+#             */
/*   Updated: 2026/03/14 09:50:37 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " created!" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " has been destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
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
	else
	{
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << _name << " is alerady dead." << std::endl;
		return ;
	}
	if (amount >= (unsigned int)_hitPoints)
	{
		_hitPoints = 0;
	}
	else
	{
		_hitPoints -= amount;	
	}
	std::cout << "ClapTrap " << _name << " takes " << amount << " damage, remaining HP: " << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0) {
		std::cout << _name << " is dead and can't repair.\n";
		return;
	}
	if (_energyPoints <= 0) {
		std::cout << _name << " has no energy to repair.\n";
		return;
	}
	_energyPoints--;        // cost to repair
	_hitPoints += amount;   // heal HP
	std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " points, new HP: " << _hitPoints << "\n";
}