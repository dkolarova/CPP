/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 21:12:48 by diana             #+#    #+#             */
/*   Updated: 2026/03/10 21:38:29 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// default const

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// converts an integer to fixed-point representation
Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	_value = n << _fractionalBits;
}

// converts a floating-point number to fixed-point
Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(n * (1 << _fractionalBits));
}

// coppy constructor
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// copy assignmeny operator
Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assigment operator called" << std::endl;

	if (this != &other)
		_value = other.getRawBits();

	return *this;
}

int Fixed::getRawBits(void) const
{
	return _value;
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float Fixed::toFloat(void) const
{
	return (float)_value / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
	return _value >> _fractionalBits;
}

// allows printing the object with std::cout
std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}