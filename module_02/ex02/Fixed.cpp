/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 07:30:41 by diana             #+#    #+#             */
/*   Updated: 2026/03/11 08:01:01 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructor

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const int n)
{
	_value = n << _fractionalBits;
}

Fixed::Fixed(const float n)
{
	_value = roundf(n * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed::~Fixed(){}

// Copy assigment

Fixed& Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		_value = other._value;
	return *this;
}

// Setters

int Fixed::getRawBits(void) const
{
	return _value;
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

// Conversions

float Fixed::toFloat(void) const
{
	return (float)_value / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
	return _value >> _fractionalBits;
}

// Comparision operators

bool Fixed::operator>(const Fixed &other) const
{
	return _value > other._value;
}

bool Fixed::operator<(const Fixed &other) const
{
	return _value < other._value;
}

bool Fixed::operator>=(const Fixed &other) const
{
	return _value >= other._value;
}

bool Fixed::operator<=(const Fixed &other) const
{
	return _value <= other._value;
}

bool Fixed::operator==(const Fixed &other) const
{
	return _value == other._value;
}

bool Fixed::operator!=(const Fixed &other) const
{
	return _value != other._value;
}

// Arithmetic operators

Fixed Fixed::operator+(const Fixed &other) const
{
	return Fixed(this->toFloat() + other.toFloat()); 
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return Fixed(this->toFloat() - other.toFloat()); 
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return Fixed(this->toFloat() * other.toFloat()); 
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return Fixed(this->toFloat() / other.toFloat()); 
}

// increment and decrement

Fixed& Fixed::operator++()
{
	_value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	_value++;
	return temp;
}

Fixed& Fixed::operator--()
{
	_value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	_value--;
	return temp;
}

// min

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

// max

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

// ostream operator

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}