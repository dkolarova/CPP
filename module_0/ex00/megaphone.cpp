/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 21:19:20 by diana             #+#    #+#             */
/*   Updated: 2026/03/05 16:32:33 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int ac, char **av)
{
	if (ac == 1)
		std:: cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < ac; i++)
		{
			for (int j = 0; av[i][j]; j++)
				std:: cout << static_cast<char>(std::toupper(av[1][j]));
		}
	}
	std:: cout << std::endl;
	return (0);
}

/* int main(int ac, char **av)
{
	int i = 0;
	int j = 0;
	
	if (ac == 1)
		std:: cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		while (i < ac)
		{
			while (av[i][j])
			{
				std:: cout << static_cast<char>(std::toupper(av[1][j]));
				j++;
			}
			i++;
		}
	}
	std:: cout << std:: endl;
	return (0);
} 
