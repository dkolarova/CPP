/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:27:31 by dkolarov          #+#    #+#             */
/*   Updated: 2026/03/06 17:17:52 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	this->_name = "Unnamed";
}

Zombie::Zombie(std::string _name)
{
	this->_name = _name;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " is destroyed" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string _name)
{
	this->_name = _name;
}
