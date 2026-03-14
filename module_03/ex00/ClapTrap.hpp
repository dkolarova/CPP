/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:35:31 by diana             #+#    #+#             */
/*   Updated: 2026/03/13 16:18:40 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
	private:
		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;

	public:
		 // contructor & destructor
		ClapTrap(const std::string& name);
		~ClapTrap();
		// member funcs
		void attack(const std::string& target);
		void takeDamage(unsigned int amout);
		void beRepaired(unsigned int amount);
};

#endif