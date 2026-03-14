/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 16:33:49 by diana             #+#    #+#             */
/*   Updated: 2026/03/14 09:55:16 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

/* 
class ScavTrap : public ClapTrap

This means:

ScavTrap inherits from ClapTrap
*/

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(const std::string& name);
		~ScavTrap();

	void attack(const std::string& target);
	void guardGate();
};

/* 
So ScavTrap automatically gets:

attack()
takeDamage()
beRepaired()

and the data:

_name
_hitPoints
_energyPoints
_attackDamage

(Important note: this only works if those members are protected in ClapTrap. If they are private, ScavTrap cannot access them.)
*/

#endif