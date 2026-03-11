/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZomie.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 12:45:14 by dkolarov          #+#    #+#             */
/*   Updated: 2026/03/06 14:03:19 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string _name)
{
	Zombie* zombie = new Zombie(_name);
	return zombie;
}