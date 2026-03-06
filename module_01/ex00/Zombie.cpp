/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 12:45:00 by dkolarov          #+#    #+#             */
/*   Updated: 2026/03/06 14:22:23 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//contructor implementation
Zombie::Zombie(std::string name)
{
	//name = zombieName;
	this->_name = name;
}

Zombie::~Zombie()
{
	std::cout << _name << " is destroyed" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
