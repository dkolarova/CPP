/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:35:34 by dkolarov          #+#    #+#             */
/*   Updated: 2026/03/10 14:32:13 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// initializes the fixed-point value to 0
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

// creates a new object as a copy of another Fixed object
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// copies the value from one existing object to another
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &other)
		_value = other.getRawBits();

	return *this;
}

// called when the object is destroyed
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

//  returns the raw integer value of the fixed-point number
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

// sets the raw integer value of the fixed-point number
void Fixed::setRawBits(int const raw)
{
	_value = raw;
}