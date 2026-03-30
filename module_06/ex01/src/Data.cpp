/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 16:26:42 by dkolarov          #+#    #+#             */
/*   Updated: 2026/03/30 16:36:54 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : id(0), name("") {}

Data::Data(int i, const std::string& n) : id(i), name(n) {}

Data::Data(const Data& other) : id(other.id), name(other.name) {}

Data& Data::operator=(const Data &other)
{
	if (this != &other)
	{
		id = other.id;
		name = other.name;
	}
	return *this;
}

Data::~Data() {}