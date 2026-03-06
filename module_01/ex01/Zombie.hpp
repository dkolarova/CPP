/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:27:16 by dkolarov          #+#    #+#             */
/*   Updated: 2026/03/06 14:55:49 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <sstream>

class Zombie
{
	private:
		std::string _name;

	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();

	void	announce(void);
	void	setName(std::string _name);
};

#endif