/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 16:01:53 by dkolarov          #+#    #+#             */
/*   Updated: 2026/03/24 07:28:16 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = other;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat assigment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const 
{
	std::cout << "Meouw" << std::endl;
}
