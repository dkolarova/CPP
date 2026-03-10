/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:35:25 by dkolarov          #+#    #+#             */
/*   Updated: 2026/03/10 13:39:40 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int _value;
	static const int _fractionalBits = 8;

public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif