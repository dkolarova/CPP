/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:27:01 by dkolarov          #+#    #+#             */
/*   Updated: 2026/03/06 15:17:33 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name);

int main()
{
	int N = 9;
	Zombie* horde = zombieHorde(N, "HordeZombie");

	for (int i = 0; i < N; i++)
		horde[i].announce();

	delete[] horde;
	return 0;
}