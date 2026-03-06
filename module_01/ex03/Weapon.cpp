/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:40:36 by dkolarov          #+#    #+#             */
/*   Updated: 2026/03/06 17:18:42 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->_type = type;
}

Weapon::~Weapon(){}

const std::string& Weapon::getType() const
{
	return this->_type;
}

void Weapon::setType(const std::string& newType)
{
	this->_type = newType;
}